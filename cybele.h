#ifndef CYBELE_H
#define CYBELE_H
#include "config.h"

#ifdef QT_SCRIPT_LIB
#  include  <QScriptEngine>
#endif
#include <QtCore/qglobal.h>
#include <QtOpenGL/qgl.h>
#include <QMainWindow>
#include <QVector>
#include <QList>
#include <QFileInfo>
#include <QStringList>
#include <QSet>
#include <QtDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>
#include <QHeaderView>
#include <QMenu>
#include <QMenuBar>
#include <QChar>
#include <QAction>
#include <QShortcut>
#include <QKeySequence>
#include <QLibrary>
#include <QPluginLoader>
#include <QMessageBox>
#include <QScrollBar>
#include <QColor>
#include <QColorDialog>
#include <QClipboard>
#include <QCloseEvent>
#include <QInputDialog>
#include <QTreeView>
#include <QSortFilterProxyModel>
#include <QMap>
#include <QStandardItemModel>
#include <QStandardItem>

#include <stdexcept>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm> 
#include <string>
#include <list>

#ifdef QT_SCRIPT_LIB
#  include <QScriptValue>
#  ifdef QT_SCRIPTTOOLS_LIB
#    include <QScriptEngineDebugger>
#  endif
#endif
#include "Polyhedron_demo_plugin_interface.h"
#include "Polyhedron_demo_io_plugin_interface.h"
#include "Polyhedron_demo_plugin_helper.h"

#include <CGAL/IO/read_off_points.h>
#include <CGAL/IO/write_off_points.h>
#include <CGAL/AABB_intersections.h>
#include <CGAL/gl.h>
#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/AABB_face_graph_triangle_primitive.h>
#include <CGAL/internal/AABB_tree/AABB_drawing_traits.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/bounding_box.h>
#include <CGAL/Qt/DemosMainWindow.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Triangulation_3.h>
#include <CGAL/squared_distance_3.h>
#include <CGAL/Point_3.h>
#include <CGAL/Segment_3.h>
#include <CGAL/squared_distance_2.h>
#include <CGAL/Point_2.h>
#include <CGAL/spatial_sort.h>
#include <CGAL/HalfedgeDS_vertex_base.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Constrained_triangulation_plus_2.h>
#include <CGAL/IO/io.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Gmpq.h>

#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/Polygon_mesh_processing/compute_normal.h>
#include <CGAL/Polygon_mesh_processing/triangulate_hole.h>
#include <CGAL/spatial_sort.h>
#include <CGAL/Qt/debug.h>

#include <CGAL/pca_estimate_normals.h>
#include <CGAL/mst_orient_normals.h>
#include <CGAL/property_map.h>

// INCLUDES FOR POISSON
#include <CGAL/compute_average_spacing.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/Surface_mesh_default_triangulation_3.h>
#include <CGAL/make_surface_mesh.h>
#include <CGAL/Implicit_surface_3.h>
#include <CGAL/IO/output_surface_facets_to_polyhedron.h>
#include <CGAL/Poisson_reconstruction_function.h>
#include <CGAL/Point_with_normal_3.h>

#include <QGLViewer/manipulatedCameraFrame.h>
#include <QGLViewer/manipulatedFrame.h>

#include "Scene_polylines_item.h"
#include "ui_cybele.h"
#include "ui_Preferences.h"
#include "Scene_points_with_normal_item.h"
#include "Show_point_dialog.h"
#include "File_loader_dialog.h"
#include "Scene.h"
#include "Scene_item.h"
#include "Scene_polyhedron_item.h"
#include "Scene_polyhedron_selection_item.h"
#include "Point_set_3.h"
#include "Polyhedron_type.h"
#include "Scene_plane_item.h"
#include "Messages_interface.h"
#include "formextractor.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <CGAL/boost/graph/graph_traits_Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/triangulate_faces.h>
#include <CGAL/Polygon_mesh_processing/stitch_borders.h>
#include <CGAL/Polygon_mesh_processing/repair.h>
#include <CGAL/Polygon_mesh_processing/self_intersections.h>
#include <boost/foreach.hpp>


#include <CGAL/Polygon_mesh_processing/orient_polygon_soup.h>
#include <CGAL/Polygon_mesh_processing/polygon_soup_to_polygon_mesh.h>
#include <CGAL/Polygon_mesh_processing/orientation.h>

typedef Kernel::Point_3 Point_3;
typedef Point_set_3<Kernel> Point_set;
typedef Point_set::UI_point UI_point; // type of points in Point_set_3

typedef CGAL::Exact_predicates_inexact_constructions_kernel Epic_kernel;
typedef CGAL::AABB_face_graph_triangle_primitive<Polyhedron>     AABB_primitive;
typedef CGAL::AABB_traits<Epic_kernel, AABB_primitive>           AABB_traits;
typedef CGAL::AABB_tree<AABB_traits>                            AABB_tree;

typedef Epic_kernel::Point_3 Point;
typedef Epic_kernel::Vector_3 Vector;
typedef CGAL::Point_with_normal_3<Epic_kernel> Point_with_normal;
typedef std::vector<Point_with_normal> PointList;
//typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

// Point with normal vector stored in a std::pair.
typedef std::pair<Point, Vector> PointVectorPair;
typedef std::vector<PointVectorPair> ListPointVector;

typedef CGAL::Polyhedron_3<Epic_kernel>     PolyMesh;
typedef PolyMesh::Halfedge_handle    Halfedge_handle;
typedef PolyMesh::Facet_handle       Facet_handle;
typedef PolyMesh::Vertex_handle      Vertex_handle;

typedef CGAL::Surface_mesh<Point> Surface_mesh;
typedef boost::graph_traits<PolyMesh>::vertex_descriptor vertex_descriptor;
typedef boost::graph_traits<PolyMesh>::face_descriptor   face_descriptor;

typedef Epic_kernel::FT FT;
typedef Kernel::Sphere_3 Sphere;

typedef CGAL::Polyhedron_3<Epic_kernel> Polyhedron_K;
typedef CGAL::Poisson_reconstruction_function<Epic_kernel> Poisson_reconstruction_function;
typedef CGAL::Surface_mesh_default_triangulation_3 STr;
typedef CGAL::Surface_mesh_complex_2_in_triangulation_3<STr> C2t3;
typedef CGAL::Implicit_surface_3<Epic_kernel, Poisson_reconstruction_function> Surface_3;

class Scene;
class Viewer;
class QTreeView;
class QMenu;
class Polyhedron_demo_io_plugin_interface;
class Polyhedron_demo_plugin_interface;
class Scene_item;
class QSortFilterProxyModel;

namespace Ui {
class Cybele;
}

class Q_DECL_EXPORT Scene_bbox_item : public Scene_item
{
	Q_OBJECT
public:
	Scene_bbox_item(const Scene_interface* scene_interface)
		: Scene_item(1, 1), scene(scene_interface)
	{
		positions_lines.resize(0);
		//box_3 = CGAL::Bbox_3(boundingBox.xmin(), boundingBox.ymin(), boundingBox.zmin(), boundingBox.xmax(), boundingBox.ymax(), boundingBox.zmax());
		//Generates an integer which will be used as ID for each buffer
	}
	~Scene_bbox_item()
	{
	}
	std::vector<float> lines;
	bool isFinite() const { return true; }
	bool isEmpty() const { return true; }
	Bbox bbox() const { return Bbox(); }
	//CGAL::Bbox_3 box_3;
	CGAL::Bbox_3 box_3() const { return CGAL::Bbox_3(); }
	Scene_bbox_item* clone() const {
		return 0;
	}

	QString toolTip() const {
		const Bbox& bb = scene->bbox();
		return QString("<p><b>Scene bounding box</b></p>"
			"<p>x range: (%1, %2)<br />"
			"y range: (%3, %4)<br />"
			"z range: (%5, %6)</p>")
			.arg(bb.xmin).arg(bb.xmax)
			.arg(bb.ymin).arg(bb.ymax)
			.arg(bb.zmin).arg(bb.zmax);
	}

	// Indicate if rendering mode is supported
	bool supportsRenderingMode(RenderingMode m) const {
		return (m == Wireframe);
	}

	void draw_edges(Viewer_interface* viewer) const
	{
		if (!are_buffers_filled)
			initialize_buffers(viewer);
		vaos[0]->bind();
		program = getShaderProgram(PROGRAM_WITHOUT_LIGHT);
		attrib_buffers(viewer, PROGRAM_WITHOUT_LIGHT);
		program->bind();
		program->setAttributeValue("colors", this->color());
		viewer->glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(positions_lines.size() / 3));
		vaos[0]->release();
		program->release();

	}

	void invalidate_buffers()
	{
		compute_elements();
		are_buffers_filled = false;
	}

private:

	std::vector<float> positions_lines;
	mutable QOpenGLShaderProgram *program;
	using Scene_item::initialize_buffers;
	void initialize_buffers(Viewer_interface *viewer)const
	{

		//vao containing the data for the lines
		{
			program = getShaderProgram(PROGRAM_WITHOUT_LIGHT, viewer);
			program->bind();

			vaos[0]->bind();
			buffers[0].bind();
			buffers[0].allocate(positions_lines.data(),
				static_cast<GLsizei>(positions_lines.size()*sizeof(float)));
			program->enableAttributeArray("vertex");
			program->setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
			buffers[0].release();

			vaos[0]->release();
			program->release();

		}
		are_buffers_filled = true;
	}

	

	void compute_elements()
	{
		positions_lines.clear();

		positions_lines = lines;

	
	/*
		Kernel::Point_3 a(-0.11401200000000000, 0.0027570500000000000, 0.21384100000000000);
		Kernel::Point_3 b(-0.0064117999999999996, 0.046622200000000003, 0.21884300000000001);
		Kernel::Point_3 c(0.049186599999999997, -0.056083700000000000, 0.21255199999999999);
		Kernel::Point_3 d(-0.044841800000000001, -0.081323900000000005, 0.21241199999999999);

		Kernel::Point_3 a(0.018252600000000001, -0.025993599999999999, -0.10114099999999999);
		Kernel::Point_3 b(0.058771999999999998, 0.0037752100000000002, -0.091562599999999994);
		Kernel::Point_3 c(0.098318100000000005, -0.065202200000000002, -0.084362000000000006);
		Kernel::Point_3 d(0.042104500000000003, -0.088278099999999998, -0.099194699999999997);
		const Epic_kernel::Point_3& p = a;
		const Epic_kernel::Point_3& q = b;
		const Epic_kernel::Point_3& r = c;
		const Epic_kernel::Point_3& s = d;
		const Epic_kernel::Line_3 l(a, b);

		const Epic_kernel::Plane_3 plane(p, q, r);

		const Epic_kernel::Tetrahedron_3 t(a, b, c, d);
		const Epic_kernel::Triangle_3 tgl(p, q, r);

		std::size_t size = 4;
		std::vector<Kernel::Point_3> vec;
		double minX, minY, minZ, maxX, maxY, maxZ;
		vec.reserve(size);
		vec.push_back(p);
		vec.push_back(q);
		vec.push_back(r);
		vec.push_back(s);

		// Point Sorting
		std::sort(vec.begin(), vec.end(), myobjectX);
		minX = vec[0].x();
		maxX = vec[3].x();

		std::sort(vec.begin(), vec.end(), myobjectY);
		minY = vec[0].y();
		maxY = vec[3].y();

		std::sort(vec.begin(), vec.end(), myobjectZ);
		minZ = vec[0].z();
		maxZ = vec[3].z();
		Kernel::Point_3 maxPoint(maxX, maxY, maxZ);
		Kernel::Point_3 minPoint(minX, minY, minZ);
		const Epic_kernel::Circle_3 circ(vec[1], vec[2], vec[0]);
		*/
		//const CGAL::Bbox_3 box_3(minX, minY, minZ, maxX, maxY, maxZ);

		
	}

	const Scene_interface* scene;
};

class Q_DECL_EXPORT Scene_aabb_item : public Scene_item
{
	Q_OBJECT
public:
	Scene_aabb_item(const AABB_tree& tree_) : Scene_item(1, 1), tree(tree_)
	{
		positions_lines.resize(0);
	}

	~Scene_aabb_item()
	{
	}

	bool isFinite() const { return true; }
	bool isEmpty() const { return tree.empty(); }
	Bbox bbox() const {
		const CGAL::Bbox_3 bbox = tree.bbox();
		return Bbox(bbox.xmin(),
			bbox.ymin(),
			bbox.zmin(),
			bbox.xmax(),
			bbox.ymax(),
			bbox.zmax());
	}

	Scene_aabb_item* clone() const {
		return 0;
	}

	QString toolTip() const {
		return
			tr("<p><b>%1</b> (mode: %2, color: %3)<br />"
			"<i>AABB_tree</i></p>"
			"<p>Number of nodes: %4</p>")
			.arg(this->name())
			.arg(this->renderingModeName())
			.arg(this->color().name())
			.arg(tree.size());
	}


	// Indicate if rendering mode is supported
	bool supportsRenderingMode(RenderingMode m) const {
		return (m == Wireframe);
	}

	// Wireframe OpenGL drawing in a display list
	void invalidate_buffers()
	{
		compute_elements();
		are_buffers_filled = false;
	}
public:
	const AABB_tree& tree;
private:
	std::vector<float> positions_lines;

	mutable QOpenGLShaderProgram *program;

	using Scene_item::initialize_buffers;
	void initialize_buffers(Viewer_interface *viewer)const
	{
		program = getShaderProgram(PROGRAM_WITHOUT_LIGHT, viewer);
		program->bind();
		vaos[0]->bind();

		buffers[0].bind();
		buffers[0].allocate(positions_lines.data(),
			static_cast<int>(positions_lines.size()*sizeof(float)));
		program->enableAttributeArray("vertex");
		program->setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
		buffers[0].release();
		program->release();

		vaos[0]->release();
		are_buffers_filled = true;
	}

	void compute_elements()
	{
		positions_lines.clear();

		CGAL::AABB_drawing_traits<AABB_primitive, CGAL::AABB_node<AABB_traits> > traits;
		traits.v_edges = &positions_lines;

		tree.traversal(0, traits);
	}
	void draw_edges(Viewer_interface* viewer) const
	{
		if (!are_buffers_filled)
			initialize_buffers(viewer);
		vaos[0]->bind();
		program = getShaderProgram(PROGRAM_WITHOUT_LIGHT);
		attrib_buffers(viewer, PROGRAM_WITHOUT_LIGHT);
		program->bind();
		program->setAttributeValue("colors", this->color());
		viewer->glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(positions_lines.size() / 3));
		program->release();
		vaos[0]->release();
	}
}; // end class Scene_aabb_item

class Q_DECL_EXPORT Scene_edges_item : public Scene_item
{
	Q_OBJECT
public:
	Scene_edges_item() :Scene_item(1, 1)
	{
		positions_lines.resize(0);
		top = true;
	}
	~Scene_edges_item()
	{
	}
	bool isFinite() const { return true; }
	bool isEmpty() const { return edges.empty(); }
	Bbox bbox() const {
		if (isEmpty())
			return Bbox();
		CGAL::Bbox_3 bbox = edges.begin()->bbox();
		for (size_t i = 1, end = edges.size(); i < end; ++i) {
			bbox = bbox + edges[i].bbox();
		}
		return Bbox(bbox.xmin(),
			bbox.ymin(),
			bbox.zmin(),
			bbox.xmax(),
			bbox.ymax(),
			bbox.zmax());
	}
	void invalidate_buffers()
	{
		compute_elements();
		are_buffers_filled = false;
	}

	Scene_edges_item* clone() const {
		Scene_edges_item* item = new Scene_edges_item();
		item->edges = edges;
		return item;
	}

	QString toolTip() const {
		return
			tr("<p><b>%1</b> (mode: %2, color: %3)<br />"
			"<i>Edges</i></p>"
			"<p>Number of edges: %4</p>")
			.arg(this->name())
			.arg(this->renderingModeName())
			.arg(this->color().name())
			.arg(edges.size());
	}

	// Indicate if rendering mode is supported
	bool supportsRenderingMode(RenderingMode m) const {
		return (m == Wireframe);
	}



	bool save(std::ostream& os) const
	{
		os.precision(17);
		for (size_t i = 0, end = edges.size(); i < end; ++i){
			os << "2 " << edges[i].source() << " " << edges[i].target() << "\n";
		}
		return true;
	}

public:
	std::vector<Epic_kernel::Segment_3> edges;
	bool top;

private:
	std::vector<float> positions_lines;
	void timerEvent(QTimerEvent* )
	{
		top = true;
	}

	mutable QOpenGLShaderProgram *program;

	using Scene_item::initialize_buffers;
	void initialize_buffers(Viewer_interface *viewer)const
	{
		program = getShaderProgram(PROGRAM_WITHOUT_LIGHT, viewer);
		program->bind();
		vaos[0]->bind();

		buffers[0].bind();
		buffers[0].allocate(positions_lines.data(),
			static_cast<int>(positions_lines.size()*sizeof(float)));
		program->enableAttributeArray("vertex");
		program->setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
		buffers[0].release();
		program->release();

		vaos[0]->release();
		are_buffers_filled = true;
	}
	void compute_elements()
	{
		positions_lines.clear();

		for (size_t i = 0, end = edges.size();
			i < end; ++i)
		{
			const Epic_kernel::Point_3& a = edges[i].source();
			const Epic_kernel::Point_3& b = edges[i].target();
			positions_lines.push_back(a.x()); positions_lines.push_back(a.y()); positions_lines.push_back(a.z());
			positions_lines.push_back(b.x()); positions_lines.push_back(b.y()); positions_lines.push_back(b.z());
		}
	}
	void draw_edges(Viewer_interface* viewer) const
	{
		if (!are_buffers_filled)
			initialize_buffers(viewer);
		vaos[0]->bind();
		program = getShaderProgram(PROGRAM_WITHOUT_LIGHT);
		attrib_buffers(viewer, PROGRAM_WITHOUT_LIGHT);
		program->bind();
		program->setAttributeValue("colors", this->color());
		viewer->glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(positions_lines.size() / 3));
		vaos[0]->release();
		program->release();

	}

}; // end class Scene_edges_item

class Cybele : 
	public CGAL::Qt::DemosMainWindow,
	public Messages_interface
{
	Q_OBJECT
		Q_INTERFACES(Messages_interface)
		
public:
    explicit Cybele(QWidget *parent = 0) ;
    ~Cybele();

	/// Find an IO plugin.
	/// @throws `std::invalid_argument` if no loader with that argument can be found
	/// @returns the IO plugin associated with `loader_name`
	Polyhedron_demo_io_plugin_interface* find_loader(const QString& loader_name) const;

	/// Load an item with a given loader.
	///
	/// @throws `std::logic_error` if loading does not succeed or
	/// `std::invalid_argument` if `fileinfo` specifies an invalid file
	Scene_item* load_item(QFileInfo fileinfo, Polyhedron_demo_io_plugin_interface*);
	

public Q_SLOTS:
	void updateViewerBBox();
	void open(QString);
	
	/// given a file extension file, returns true if `filename` matches the filter
	bool file_matches_filter(const QString& filters, const QString& filename);
	bool hasPlugin(const QString&) const;
	void information(QString);
	void warning(QString);
	void error(QString);
	void message(QString, QString, QString = QString("normal"));
	double getCircumference();
	double computeMeasure(Scene_edges_item*);
	double getDistanceBetweenPoints(CGAL::Point_3<CGAL::Cartesian<double>> q, CGAL::Point_3<CGAL::Cartesian<double>> p);
	void setAddKeyFrameKeyboardModifiers(Qt::KeyboardModifiers);
	void enableScriptDebugger(bool = true);
	void selectSceneItem(int i);
	void showSelectedPoint(double, double, double);
	void unSelectSceneItem(int i);
	void addSceneItemInSelection(int i);
	void removeSceneItemFromSelection(int i); // same as unSelectSceneItem

	void selectAll();
	
	
	bool load_script(QString filename);
	bool load_script(QFileInfo);
	
	void clearMenu(QMenu*);
	void addAction(QAction*);
	void addAction(QString actionName,
		QString actionText,
		QString menuName);
	void viewerShow(float, float, float);
	void viewerShow(float, float, float, float, float, float);
	void viewerShowObject();
	/// Reloads an item. Expects to be called by a QAction with the
	/// index of the item to be reloaded as data attached to the action.
	/// The index must identify a valid `Scene_item`.
	void reload_item();
protected:
	void loadPlugins();
	bool initPlugin(QObject*);
	bool initIOPlugin(QObject*);
	bool onePolygonIsSelected() const;
	void closeEvent(QCloseEvent *event);
	QList<int> getSelectedSceneItemIndices() const;
	int getSelectedSceneItemIndex() const;
	void load_off(QString absoluteFilePath);
	void PoissonReconstruction(const char* filename, const char* filename_out );
	void calculatePointSetNormals(const char* filename, const char* filename_out);

protected Q_SLOTS:
	void selectionChanged();

	void contextMenuRequested(const QPoint& global_pos);
	void showSceneContextMenu(int selectedItemIndex, const QPoint& global_pos);
	void showSceneContextMenu(const QPoint& local_pos_of_treeview);
	
	void updateInfo();
	void updateDisplayInfo();
	void removeManipulatedFrame(Scene_item*);

	// settings
	void quit();
	void readSettings();
	void writeSettings();

	// load, erase, duplicate
	void on_actionEraseAll_triggered();
	void on_actionLoad_triggered();
	bool on_actionErase_triggered();
	void on_actionDuplicate_triggered();
	void on_actionLoad_Script_triggered();

	// Show/Hide
	void on_actionShowHide_triggered();

	// Select A/B
	void on_actionSetPolyhedronA_triggered();
	void on_actionSetPolyhedronB_triggered();

	//Preferences edition
	void on_actionPreferences_triggered();
	// save as...
	void on_actionSaveAs_triggered();
	void save(QString filename, Scene_item* item);
	void on_actionSaveSnapshot_triggered();
	void on_actionSetBackgroundColor_triggered();
	void on_action_Look_at_triggered();
	QString camera_string() const;
	void on_actionDumpCamera_triggered();
	void on_action_Copy_camera_triggered();
	void on_action_Paste_camera_triggered();

	void filterOperations();
	Scene_plane_item* createCutPlane(QString, Scene_points_with_normal_item*);
	CGAL::Bbox_3 createBBox(Scene_points_with_normal_item*);
	void cut(QString, Scene_plane_item* plane_item, Scene_points_with_normal_item*, Scene_edges_item**);
	Scene_points_with_normal_item* createMeasureItem(QString);
	bool findSegment(Epic_kernel::Segment_3 inter_seg, Scene_edges_item*);
	void searchSegment(Scene_edges_item*, Scene_edges_item*, Epic_kernel::Point_3 source, Epic_kernel::Point_3 target);
	bool checkTargets(Epic_kernel::Point_3 target, Epic_kernel::Point_3 t, Epic_kernel::Point_3 s);
	bool checkSources(Epic_kernel::Point_3 source, Epic_kernel::Point_3 s, Epic_kernel::Point_3 t);
	void setBboxLines(Scene_bbox_item* item, CGAL::Bbox_3 box_3);
	QString extractMeasure(QString, Scene_plane_item* plane_item, Scene_points_with_normal_item*, Scene_edges_item*);
	void on_actionRecenterScene_triggered();
	void on_btn_CircunCefalica_clicked();
	void on_btn_CircunBrazoIzq_clicked();
	void on_btn_CircunCintura_clicked();
	void on_btn_CircunCadera_clicked();
	void on_btn_CircunMusloIzq_clicked();
	void on_btn_DiamMuneca_clicked();
	void on_btn_DiamFemur_clicked();
	void on_btn_Talla_clicked();
private slots:

        void on_btn_selection_clicked();

private:
    Ui::Cybele *ui;
	Viewer* viewer;
	Viewer* viewer_2;
	QTreeView* sceneView;
	Scene* scene;	
	Scene* scene_2;
	/// plugin black-list
	QSet<QString> plugin_blacklist;
	// typedef to make Q_FOREACH work
	typedef QPair<Polyhedron_demo_plugin_interface*, QString> PluginNamePair;
	QVector<PluginNamePair > plugins;
	QVector<Polyhedron_demo_io_plugin_interface*> io_plugins;
	QSortFilterProxyModel* proxyModel;
	QMap<QString, QString> default_plugin_selection;
	QString strippedName(const QString &fullFileName);
	typedef std::map<QObject*, AABB_tree*> Trees;
	Trees trees;
	FormExtractor *centralWidget;
	Scene_edges_item* edges_item;
	Scene_edges_item* outside_edges_item;
	Scene_edges_item* inside_edges_item;
	// TALLA
	Scene_plane_item* plane_talla; // plane_item
	Scene_edges_item* edges_talla, oedges_talla, iedges_talla; // edges_item
	// Circunferencia Cefalica
	Scene_points_with_normal_item* points_CircunCefalica;
	Scene_plane_item* plane_CircunCefalica;
	Scene_edges_item* edges_CircunCefalica, oedges_CircunCefalica, iedges_CircunCefalica;
	// Circunferencia brazo Izquierdo
	Scene_plane_item* plane_CircunBrazoIzq;
	Scene_edges_item* edges_CircunBrazoIzq, oedges_CircunBrazoIzq, iedges_CircunBrazoIzq;
	Scene_points_with_normal_item* points_CircunBrazoIzq;
	// Circunferencia Cintura
	Scene_points_with_normal_item* points_CircunCintura;
	Scene_plane_item* plane_CircunCintura;
	Scene_edges_item* edges_CircunCintura, oedges_CircunCintura, iedges_CircunCintura;

	Scene_points_with_normal_item* points_CircunCadera;
	Scene_plane_item* plane_CircunCadera;
	Scene_edges_item* edges_CircunCadera, oedges_CircunCadera, iedges_CircunCadera;

	Scene_points_with_normal_item* points_CircunMusloIzq;
	Scene_plane_item* plane_CircunMusloIzq;
	Scene_edges_item* edges_CircunMusloIzq, oedges_CircunMusloIzq, iedges_CircunMusloIzq;

	Scene_points_with_normal_item* points_DiamMuneca;
	Scene_plane_item* plane_DiamMuneca;
	Scene_edges_item* edges_DiamMuneca, oedges_DiamMuneca, iedges_DiamMuneca;

	Scene_points_with_normal_item* points_DiamFemur;
	Scene_plane_item* plane_DiamFemur;
	Scene_edges_item* edges_DiamFemur, oedges_DiamFemur, iedges_DiamFemur;

	double d_CircunCefalica, d_CircunBrazoIzq, d_CircunCintura, d_CircunCadera, d_CircunMusloIzq, d_DiamMuneca, d_DiamFemur;
	//Scene_polyhedron_selection_item* new_item,
	//Scene_edges_item* edges_item;// , outside_edges_item, inside_edges_item;

#ifdef QT_SCRIPT_LIB
	QScriptEngine* script_engine;
public:
	void evaluate_script(QString script,
		const QString & fileName = QString(),
		const bool quiet = false);
	void evaluate_script_quiet(QString script,
		const QString & fileName = QString());
#endif
};

#endif // CYBELE_H
