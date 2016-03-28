#include "openglviewer.h"
#include <QtDebug>

OpenGLViewer::OpenGLViewer(QWidget *parent) : QOpenGLWidget(parent)
//    cloud_xyz(new pcl::PointCloud<pcl::PointXYZ>),
//    cloud_indices(new pcl::PointIndices())
{
rotation_angle = 0;
dz = 0;
dx = 0;
dy = 0;
currentTime = lastTime = QDateTime();
eye = QVector3D(0,0,5);
center = QVector3D(0,0,0);
direction = QVector3D(0,0,0);
}

void OpenGLViewer::initializeGL()
{
    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void OpenGLViewer::paintGL()
{
	
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity ();             /* clear the matrix */
    //gluLookAt (eye.x(), eye.y(), eye.z(), center.x(),center.y(),center.z(), up.x(),up.y(),up.z()); //up.x(),up.y(),up.z()); /* viewing transformation  */

	/*
    //glTranslatef(eye.x(),eye.y(),eye.z());
    glTranslatef(-direction.x(),direction.y(),-direction.z());
    glRotatef(rotation_angle, 1, 0, 0);
    glRotatef(rotation_angle, 0, 1, 0);
    glRotatef(rotation_angle, 0, 0, 1);

    qDebug() << "gluLookAt:" << eye.x() << eye.y() <<eye.z() << center.x() << center.y() << center.z() << up.x() << up.y() << up.z();
    if (cloud_xyz->size() > 0)
    {
       // glRotatef(rotation_angle, 0, 1, 0);
       // glTranslatef(center.x(),center.y(),center.z());
        drawPointCloud();
    }else{

     glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, 0.5, 0);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f( 0.5, 0.5, 0);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( 0.5, -0.5, 0);

      glEnd();
    }
    // qDebug() << "glRotate:" << rotation_angle;
    // qDebug() << "glTranslate:" << direction.x() << direction.y() << direction.z();
	*/
}

void OpenGLViewer::resizeGL(int w, int h)
{
    screenW = w;
    screenH = h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45.0f, w/h, 0.1f, 100.0f);
    //glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLViewer::draw(){
    OpenGLViewer::update();
}

void OpenGLViewer::drawPointCloud(){
	/*
    glBindVertexArray(vaoId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);

    glEnableVertexAttribArray(0);

    qDebug() << "point size:" << sizeof(pcl::PointXYZ);
    qDebug() << "point[0].x:" << &cloud_xyz->points[0].x;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(pcl::PointXYZ),  (void*)0); // x y z

    glDrawArrays(GL_POINTS, 0, cloud_xyz->size());

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
	*/
}

void OpenGLViewer::buildVBOs(){
	/*
    glGenVertexArrays(1, &vaoId);
    glGenBuffers(1, &vboId);

    qDebug() << "size in bytes:" << sizeof(pcl::PointXYZ) * cloud_xyz->size();
    glBindVertexArray(vaoId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);

    glBufferData(GL_ARRAY_BUFFER, sizeof(pcl::PointXYZ) * cloud_xyz->size(), &cloud_xyz->points[0], GL_DYNAMIC_DRAW);

    glBindVertexArray(0);
	*/
}

void OpenGLViewer::mousePressEvent(QMouseEvent *event){
     last_mouse_pos = mouse_pos;
     mouse_pos = event->pos();
     lastTime = currentTime;
}

void OpenGLViewer::mouseMoveEvent(QMouseEvent *event){

    if (event->buttons() & Qt::LeftButton){
       rotation_angle += event->x() * 0.01;

       if(rotation_angle>360)
           rotation_angle = 0;

    }else if(event->buttons() & Qt::RightButton){
       currentTime = QDateTime();
       deltaTime = 0.005;
       horizontalAngle += mouseSpeed * deltaTime * float(screenW/2 - event->pos().x());
       verticalAngle   += mouseSpeed * deltaTime * float(screenH/2 - event->pos().y());
       lastTime = currentTime;
       qDebug() << "**** HorizontalAngle = MouseSpeed, deltaTime, mousePosition:" << horizontalAngle << mouseSpeed <<deltaTime <<  event->pos().x();
       qDebug() << "**** VerticalAngle = MouseSpeed, deltaTime, mousePosition:" << verticalAngle << mouseSpeed <<deltaTime <<  event->pos().y();

       // Translate
       //direction = QVector3D( event->pos().x(), event->pos().y(), 0);
       direction = QVector3D(qCos(verticalAngle) * qSin(horizontalAngle),qSin(verticalAngle),qCos(verticalAngle) * qCos(horizontalAngle));
       // Up
       right = QVector3D(qSin(horizontalAngle - 3.14f/2.0f),0,qCos(horizontalAngle - 3.14f/2.0f));

       // Camera
       if(event->pos().y() > screenH/2)
        eye += direction * deltaTime * mouseSpeed;
       else
        eye -= direction * deltaTime * mouseSpeed;

       if((event->pos().x() > screenW/2))
        eye += right * deltaTime * mouseSpeed;
       else
        eye -= right * deltaTime * mouseSpeed;

       center = eye + direction;
       up = QVector3D::crossProduct(right, direction);
    }else if(event->button() == Qt::MiddleButton){

    }
    OpenGLViewer::update();
}
void OpenGLViewer::wheelEvent(QWheelEvent *event){
    angleDelta = event->angleDelta()/8;
   // float FoV = initialFoV - 5 * angleDelta.rx()/15;
    OpenGLViewer::update();
}
