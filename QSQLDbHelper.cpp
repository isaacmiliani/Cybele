#include "QSQLDbHelper.h"

QSQLDbHelper::QSQLDbHelper(const char* driver)
{
	db = new QSqlDatabase(QSqlDatabase::addDatabase(driver));
}

QSQLDbHelper::~QSQLDbHelper()
{
	qDebug() << "Called Destructor!";
	delete db;
}

QSqlDatabase* QSQLDbHelper::connect(const QString& server,
	const QString& databaseName,
	const QString& userName,
	const QString& password)
{
	db->setConnectOptions();
	db->setHostName(server);
	db->setDatabaseName(databaseName);
	db->setUserName(userName);
	db->setPassword(password);

	if (db->open()) {
		return db;
	}
	else {
		return NULL;
	}
}

int QSQLDbHelper::selectRowCountResult(QSqlQuery* query)
{
	bool queryRes = query->exec();
	if (query->lastError().type() != QSqlError::NoError || !queryRes)
	{
		qDebug() << query->lastError().text();
		return -1;
	}

	int recordCount = 0;
	while (query->next())
	{
		qDebug() << "Field 1 : " << query->value(0).toString()
			<< "Field 2 : " << query->value(1).toString();
		++recordCount;
	}

	return recordCount;
}

bool QSQLDbHelper::executeInsert(QSqlQuery* query)
{
	db->transaction();
	bool queryRes = query->exec();
	if (query->lastError().type() != QSqlError::NoError || !queryRes)
	{
		qDebug() << query->lastError().text();
		db->rollback();
		return false;
	}
	db->commit();
	lastInsertID = query->lastInsertId().toInt();
	return true;
}

bool QSQLDbHelper::executeUpdate(QSqlQuery* query)
{
	db->transaction();
	bool queryRes = query->exec();
	if (query->lastError().type() != QSqlError::NoError || !queryRes)
	{
		qDebug() << query->lastError().text();
		db->rollback();
		return false;
	}
	db->commit();
	return true;
}

bool QSQLDbHelper::executeDelete(QSqlQuery* query)
{
	db->transaction();
	bool queryRes = query->exec();
	if (query->lastError().type() != QSqlError::NoError || !queryRes)
	{
		qDebug() << query->lastError().text();
		db->rollback();
		return false;
	}
	db->commit();
	return true;
}

void QSQLDbHelper::disConnect()
{
	qDebug() << "Disconnected From Database!";
	db->close();
}