#ifndef VIEWERQGL_H
#define VIEWERQGL_H

#include "ViewerQGL_config.h"
#include "ViewerQGL_interface.h"

#include <QGLViewer/qglviewer.h>
#include <QPoint>
#include "polyhedron.h"

// forward declarations
class QWidget;
class Scene_draw_QGLinterface;
class QMouseEvent;
class QKeyEvent;

class ViewerQGL_impl;

class VIEWERQGL_EXPORT ViewerQGL : public ViewerQGL_interface {

	Q_OBJECT

public:
	ViewerQGL(QWidget * parent, bool antialiasing = false);
	~ViewerQGL();

	// overload several QGLViewer virtual functions
	void draw();
	void fastDraw();
	void initializeGL();
	void drawWithNames();
	void postSelection(const QPoint&);
	void beginSelection(const QPoint &point);
	void endSelection(const QPoint &point);
	void setScene(Scene_draw_interface* scene);
	bool antiAliasing() const;
	//PolyhedronPtr polyhedron_ptr;

	bool inFastDrawing() const;

	public Q_SLOTS:
	void setAntiAliasing(bool b);
	void setTwoSides(bool b);

	void turnCameraBy180Degres();

	QString dumpCameraCoordinates();
	bool moveCameraToCoordinates(QString,
		float animation_duration = 0.5f);

protected:
	void mousePressEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
	void pickMatrix(GLdouble x, GLdouble y, GLdouble width, GLdouble height,
		GLint viewport[4]);

protected:
	ViewerQGL_impl* d;
}; // end class Viewer

#endif // VIEWER_H
