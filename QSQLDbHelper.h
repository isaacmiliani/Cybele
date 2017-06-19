#ifndef QSQLDBHELPER_H
#define QSQLDBHELPER_H

#include "QtSql/qtsqlglobal.h"
#include "QtSql/qsqldatabase.h"
#include "QtSql/qsqlquery.h"
#include "QtSql/qsqlerror.h"
#include <QString>
#include <QDebug>

class QSQLDbHelper
{
public:
	QSQLDbHelper(const char* driver);
	~QSQLDbHelper();
	QSqlDatabase* connect(const QString& server,
		const QString& databaseName,
		const QString& userName,
		const QString& password);
	void disConnect();

	int selectRowCountResult(QSqlQuery* query);
	bool executeInsert(QSqlQuery* query);
	bool executeUpdate(QSqlQuery* query);
	bool executeDelete(QSqlQuery* query);
	int lastInsertID;
private:
	QSqlDatabase* db;
};

#endif // QSQLDBHELPER_H