#ifndef OPENGLVIEWER_H
#define OPENGLVIEWER_H


#include <GL/glew.h>
#include <GL/freeglut.h>

#include <QOpenGLWidget>

#include <QPoint>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QVector3D>
#include <QtMath>
#include <QDateTime>


class OpenGLViewer : public QOpenGLWidget
{
public:
    OpenGLViewer(QWidget *parent = 0);
    GLuint vboId, vaoId; // Vertex buffer ID
    void draw();
    void drawPointCloud();
    void buildVBOs();
    QPoint mouse_pos, last_mouse_pos, angleDelta;
    float dx, dy, dz, rotation_angle,screenW, screenH;
    // position

    QVector3D eye; //new QVector3D(0, 0, 5 );
    QVector3D direction; //= new QVector3D(0, 0, 5 );
    QVector3D center;
    QVector3D right ; //= new QVector3D(0, 0, 5 );
    QVector3D up ; //= new QVector3D(0, 0, 5 );
    // horizontal angle : toward -Z

    float horizontalAngle = 3.14f;

    // vertical angle : 0, look at the horizon

    float verticalAngle = 0.0f;

    // Initial Field of View

    float initialFoV = 45.0f;

    float speed = 3.0f; // 3 units / second

    float mouseSpeed = 0.005f;
    QDateTime lastTime;
    float deltaTime;
    QDateTime currentTime;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private:

};

#endif // OPENGLVIEWER_H
