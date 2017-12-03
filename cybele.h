#ifndef CYBELE_H
#define CYBELE_H
#include "config.h"
#include <stdexcept>
#include <utility>
#include <fstream>
#include <iostream>
#include <algorithm> 
#include <string>
#include <list>

#ifdef QT_SCRIPT_LIB
#  include  <QScriptEngine>
#endif
#include <qglobal.h>
#include <qgl.h>
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
#include <QTimer>
#ifdef QT_SCRIPT_LIB
#  include <QScriptValue>
#  ifdef QT_SCRIPTTOOLS_LIB
#    include <QScriptEngineDebugger>
#  endif
#endif

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
#include <CGAL/intersections.h>
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
#include <CGAL/edge_aware_upsample_point_set.h>

#include <QGLViewer/manipulatedCameraFrame.h>
#include <QGLViewer/manipulatedFrame.h>
// Advancing Front Surface Reconstruction
#include <CGAL/Advancing_front_surface_reconstruction.h>
#include <CGAL/tuple.h>
//#include "formextractor.h"

#include <CGAL/boost/graph/graph_traits_Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/triangulate_faces.h>
#include <CGAL/Polygon_mesh_processing/stitch_borders.h>
#include <CGAL/Polygon_mesh_processing/repair.h>
#include <CGAL/Polygon_mesh_processing/self_intersections.h>
#include <boost/foreach.hpp>

#include <CGAL/Polygon_mesh_processing/orient_polygon_soup.h>
#include <CGAL/Polygon_mesh_processing/polygon_soup_to_polygon_mesh.h>
#include <CGAL/Polygon_mesh_processing/orientation.h>
#include <CGAL/array.h>

#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

#include "QSQLDbHelper.h"
#include "Polyhedron_demo_plugin_interface.h"
#include "Polyhedron_demo_io_plugin_interface.h"
#include "Polyhedron_demo_plugin_helper.h"
#include "Scene_polylines_item.h"
#include "ui_Preferences.h"
#include "Scene_points_with_normal_item.h"
#include "Show_point_dialog.h"
#include <File_loader_dialog.h>
#include <Scene.h>
#include <Scene_item.h>
#include "Scene_polyhedron_item.h"
#include "Scene_polyhedron_selection_item.h"
#include "Point_set_3.h"
#include "Polyhedron_type.h"
#include "Scene_plane_item.h"
#include "Messages_interface.h"
#include "dialogpatient.h"

// PCL

#include <pcl/point_types.h>
#include <pcl/common/common.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>

// VCG lib
#include<vcg/complex/complex.h>
#include<wrap/io_trimesh/import_ply.h>
#include<wrap/io_trimesh/export_off.h>
#include<wrap/ply/plylib.h>

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

// Point with normal vector stored in a std::pair.
typedef std::pair<Point, Vector> PointVectorPair;
typedef std::vector<PointVectorPair> ListPointVector;

typedef CGAL::Polyhedron_3<Epic_kernel>     PolyMesh;
typedef PolyMesh::Halfedge_handle    Halfedge_handle;
typedef PolyMesh::Facet_handle       Facet_handle;
typedef PolyMesh::Vertex_handle      Vertex_handle;

typedef CGAL::Surface_mesh<Point> Surface_mesh;
typedef boost::graph_traits<PolyMesh>::vertex_descriptor vertex_descriptor;
typedef boost::graph_traits<PolyMesh>::face_descriptor  face_descriptor;

typedef Epic_kernel::FT FT;
typedef Kernel::Sphere_3 Sphere_K;

typedef CGAL::Polyhedron_3<Epic_kernel> Polyhedron_K;
typedef CGAL::Poisson_reconstruction_function<Epic_kernel> Poisson_reconstruction_function;
typedef CGAL::Surface_mesh_default_triangulation_3 STr;
typedef CGAL::Surface_mesh_complex_2_in_triangulation_3<STr> C2t3;
typedef CGAL::Implicit_surface_3<Epic_kernel, Poisson_reconstruction_function> Surface_3;

typedef Epic_kernel::Segment_3 Segment_3;
typedef Epic_kernel::Line_3 Line_3;
typedef Epic_kernel::Intersect_3 Intersect_3;

typedef CGAL::Triangulation_3<Epic_kernel>      Triangulation;
typedef Triangulation::Cell_handle    Cell_handle;
typedef Triangulation::Vertex_handle  T_Vertex_handle;
typedef Triangulation::Locate_type    Locate_type;
typedef Triangulation::Point          T_Point;
typedef Triangulation::Facet		  T_Facet;

// Advancing Front Surface Reconstruction
typedef CGAL::cpp11::array<std::size_t, 3> Facet;

typedef CGAL::Advancing_front_surface_reconstruction<> C_Reconstruction;
typedef C_Reconstruction::Triangulation_3 Triangulation_3;
typedef C_Reconstruction::Triangulation_data_structure_2 TDS_2;

class QTreeView;
class QMenu;
class Polyhedron_demo_io_plugin_interface;
class Polyhedron_demo_plugin_interface;
class QSortFilterProxyModel;

// USE BY VCG LIB TO IMPORT/EXPORT MESHES
class MyVertex; class MyEdge; class MyFace;
struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex>   ::AsVertexType,
	vcg::Use<MyEdge>     ::AsEdgeType,
	vcg::Use<MyFace>     ::AsFaceType>{};
class MyVertex : public vcg::Vertex< MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Color4b, vcg::vertex::CurvatureDirf,
	vcg::vertex::Qualityf, vcg::vertex::Normal3f, vcg::vertex::BitFlags  >{};
class MyFace : public vcg::Face<   MyUsedTypes, vcg::face::FFAdj, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge : public vcg::Edge<   MyUsedTypes> {};
class MyMesh : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace>, std::vector<MyEdge>  > {};

class DialogOptionsWidget;
QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

using namespace QtCharts;

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
struct callback_args{
	// structure used to pass arguments to the callback function
	PointCloudT::Ptr clicked_points_3d;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewerPtr;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
};
struct Construct{
	Surface_mesh& mesh;
	template < typename PointIterator>
	Construct(Surface_mesh& mesh, PointIterator b, PointIterator e)
		: mesh(mesh)
	{
		for (; b != e; ++b){
			boost::graph_traits<Surface_mesh>::vertex_descriptor v;
			v = add_vertex(mesh);
			mesh.point(v) = *b;
		}
	}
	Construct& operator=(const Facet f)
	{
		typedef boost::graph_traits<Surface_mesh>::vertex_descriptor vertex_descriptor;
		typedef boost::graph_traits<Surface_mesh>::vertices_size_type size_type;
		mesh.add_face(vertex_descriptor(static_cast<size_type>(f[0])),
			vertex_descriptor(static_cast<size_type>(f[1])),
			vertex_descriptor(static_cast<size_type>(f[2])));
		return *this;
	}
	Construct&
		operator*() { return *this; }
	Construct&
		operator++() { return *this; }
	Construct
		operator++(int) { return *this; }
};
struct Perimeter {
	double bound;
	Perimeter(double bound)
		: bound(bound)
	{}
	// The point type that will be injected here will be
	// CGAL::Exact_predicates_inexact_constructions_kernel::Point_3
	template <typename Point>
	bool operator()(const Point& p, const Point& q, const Point& r) const
	{
		// bound == 0 is better than bound < infinity
		// as it avoids the distance computations
		if (bound == 0){
			return false;
		}
		double d = sqrt(squared_distance(p, q));
		if (d>bound) return true;
		d += sqrt(squared_distance(p, r));
		if (d>bound) return true;
		d += sqrt(squared_distance(q, r));
		return d>bound;
	}
};

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Advancing_front_surface_reconstruction<CGAL::Default, Perimeter> Reconstruction;
typedef Reconstruction::Triangulation_3 Triangulation_3;
typedef Reconstruction::Outlier_range Outlier_range;
typedef Reconstruction::Boundary_range Boundary_range;
typedef Reconstruction::Vertex_on_boundary_range Vertex_on_boundary_range;
typedef Reconstruction::Vertex_handle R_Vertex_handle;

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
	const char* driverName = "QPSQL";
	QSQLDbHelper* qSQLDbHelper;
	QSqlDatabase* db;
	void drawChart(int id_paciente);
	void drawChart_2(int id_paciente);
	QLineSeries* setSerie(QString measure);
	struct callback_args cb_args;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
	bool LoadModel();
	bool CropBoxFilter();
	pcl::PointXYZRGB min, max;
	QString cloudFileName;
public Q_SLOTS:
	void updateViewerBBox();
	void updateViewerBBox_2();
	//void open(QString);
	void open(QString, Scene *, Viewer *, bool);
	QString openFile(Scene *, Viewer *, bool);
	
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
	void selectSceneItem_2(int i);
	void showSelectedPoint(double, double, double);
	void unSelectSceneItem(int i);

	void addSceneItemInSelection(int i);
	void removeSceneItemFromSelection(int i); // same as unSelectSceneItem
	void addSceneItemInSelection_2(int i);
	void removeSceneItemFromSelection_2(int i); // same as unSelectSceneItem
	void DisplayCloud();
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

	void viewerShow_2(float, float, float);
	void viewerShow_2(float, float, float, float, float, float);
	void viewerShowObject_2();
	/// Reloads an item. Expects to be called by a QAction with the
	/// index of the item to be reloaded as data attached to the action.
	/// The index must identify a valid `Scene_item`.
	void reload_item();
	void createBox();
	void updateBox();
protected:
	
	void loadPlugins();
	bool initPlugin(QObject*);
	bool initIOPlugin(QObject*);
	bool onePolygonIsSelected() const;
	void closeEvent(QCloseEvent *event);
	QList<int> getSelectedSceneItemIndices() const;
	QList<int> getSelectedSceneItemIndices_2() const;
	int getSelectedSceneItemIndex() const;
	int getSelectedSceneItemIndex_2() const;
	void load_off(QString absoluteFilePath);
	void PoissonReconstruction(const char* filename, const char* filename_out );
	void calculatePointSetNormals(const char* filename, const char* filename_out);
	void delaunay_triangulation(const char* filename_in, const char* filename_out);
	bool upsample_point_set(const char* filename_in, const char* filename_out);
	void advancing_front_reconstruction(const char* filename_in, const char* filename_out);
	void reconstruction_outliers_boundaries(const char* filename_in, const char* filename_out);
	void reconstruction_class(const char* filename_in, const char* filename_out);
protected Q_SLOTS:
	void selectionChanged();
	void selectionChanged_2();

	void contextMenuRequested(const QPoint& global_pos);
	void showSceneContextMenu(int selectedItemIndex, const QPoint& global_pos);
	void showSceneContextMenu_2(int selectedItemIndex, const QPoint& global_pos);
	void showSceneContextMenu(const QPoint& local_pos_of_treeview);
	void showSceneContextMenu_2(const QPoint& local_pos_of_treeview);
	
	void updateInfo();
	void updateInfo_2();
	void updateDisplayInfo();
	void updateDisplayInfo_2();
	void removeManipulatedFrame(Scene_item*);
	void removeManipulatedFrame_2(Scene_item*);

	// settings
	void quit();
	void readSettings();
	void writeSettings();

	// load, erase, duplicate
	void on_actionEraseAll_triggered();
	void on_actionLoad_triggered();
	bool on_actionErase_triggered();
	bool on_actionErase_right_triggered();
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
	
	void intersectarium(Scene_edges_item* inside_edges_item, Scene_edges_item* edges_item, Scene_edges_item* outside_edges_item);
	void filterOperations();
	Scene_plane_item* createCutPlane(QString, Scene_points_with_normal_item*);
	CGAL::Bbox_3 createBBox(Scene_points_with_normal_item*);
	double cut(QString, Scene_plane_item* plane_item, Scene_points_with_normal_item*, Scene_polylines_item**, int*);
	Scene_points_with_normal_item* createMeasureItem(QString);
	bool previouslyAdded(Epic_kernel::Segment_3 inter_seg, Scene_edges_item*);
	void searchSegment(Scene_edges_item*, Scene_edges_item*, Epic_kernel::Point_3 source, Epic_kernel::Point_3 target);
	bool checkTargets(Epic_kernel::Point_3 target, Epic_kernel::Point_3 t, Epic_kernel::Point_3 s);
	bool checkSources(Epic_kernel::Point_3 source, Epic_kernel::Point_3 s, Epic_kernel::Point_3 t);
	void setBboxLines(Scene_bbox_item* item, CGAL::Bbox_3 box_3);
	bool saveModel(QString filename, QString scan_date, int, int& id);
	bool saveMeasures(int, double, double, double, double, double, double, int);
	QString extractMeasure(QString, Scene_plane_item* plane_item, Scene_points_with_normal_item*, Scene_polylines_item**, double&);
	void create_polyline(Scene_polylines_item* new_polylines_item, Scene_edges_item* edges_item);
	QString save_mesh();
	int searchPatient(QString cedula);
	int searchPatient_2(QString cedula);
	void searchModelsByPatient(int id_paciente);
	void searchModelsByPatient_2(int id_paciente);
	QString searchModelById(int id_model);
	void save_polylines(QString filepath);
	QString getFilenameByID(int id);
	void load_measures_left(int);
	void load_measures_right(int);
	void compare_models(int id_model1, int id_model2);
	void compare_models_2();
	void on_actionRecenterScene_triggered();
	void StartProgressBar2();
	void StartProgressBar();
	void FinishProgressBar();
	void FinishProgressBar2();
	void on_btn_CircunBrazoIzq_clicked();
	void on_btn_CircunCintura_clicked();
	void on_btn_CircunCadera_clicked();
	void on_btn_DiamFemur_clicked();
	

private slots:

        void on_btn_selection_clicked();
       
        void on_cbo_modelos_currentIndexChanged(int index);
        void on_searchEditRight_editingFinished();
        void on_cbo_modelos_2_currentIndexChanged(int index);
        void on_searchEditRight_2_editingFinished();
        void on_historial_btn_clicked();
        void on_open_file_btn_clicked();
        void on_btnExtraerMedidas_clicked();
        void on_cmd_savemodel_clicked();
        void on_cmd_buscarmodelo_1_clicked();
        void on_dial_x_valueChanged(int value);
        void on_dial_x_n_valueChanged(int value);
        void on_dial_y_valueChanged(int value);
        void on_dial_y_n_valueChanged(int value);
        void on_dial_z_valueChanged(int value);
		void on_dial_z_n_valueChanged(int value);
		void on_crop_box_clicked();

                void on_compare_btn_clicked();

private:
    Ui::Cybele *ui;
	Viewer* viewer;
	Viewer* viewer_right;
	QTreeView* sceneView;
	QTreeView* sceneView_right;
	Scene* scene;	
	Scene* scene_right;
	void setupRightViewer();
	QString model_filename, model_right_filename;
	
	int patient_id;
	int model_id_left, model_id_right;
	// plugin blacklist
	QSet<QString> plugin_blacklist;
	// typedef to make Q_FOREACH work
	typedef QPair<Polyhedron_demo_plugin_interface*, QString> PluginNamePair;
	QVector<PluginNamePair > plugins;
	QVector<Polyhedron_demo_io_plugin_interface*> io_plugins;
	QSortFilterProxyModel* proxyModel;
	QSortFilterProxyModel* proxyModel_2;
	QMap<QString, QString> default_plugin_selection;
	QString strippedName(const QString &fullFileName);
	typedef std::map<QObject*, AABB_tree*> Trees;
	Trees trees;

	DialogOptionsWidget *fileDialogOptionsWidget;
	QLabel *saveFileNameLabel;
	//FormExtractor *centralWidget;
	// TALLA
	Scene_plane_item* plane_talla; // plane_item
	
	// Circunferencia Cefalica
	Scene_points_with_normal_item* points_CircunCefalica;
	Scene_plane_item* plane_CircunCefalica;

	Scene_polylines_item* polyline_CircunCefalica;

	// Circunferencia brazo Izquierdo
	Scene_plane_item* plane_CircunBrazoIzq;

	Scene_points_with_normal_item* points_CircunBrazoIzq;
	Scene_polylines_item* polyline_CircunBrazoIzq;

	// Circunferencia Cintura
	Scene_points_with_normal_item* points_CircunCintura;
	Scene_plane_item* plane_CircunCintura;
	Scene_polylines_item* polyline_CircunCintura;

	Scene_points_with_normal_item* points_CircunCadera;
	Scene_plane_item* plane_CircunCadera;
	Scene_polylines_item* polyline_CircunCadera;

	Scene_points_with_normal_item* points_CircunMusloIzq;
	Scene_plane_item* plane_CircunMusloIzq;
	Scene_polylines_item* polyline_CircunMusloIzq;

	Scene_points_with_normal_item* points_DiamMuneca;
	Scene_plane_item* plane_DiamMuneca;
	Scene_polylines_item* polyline_DiamMuneca;

	Scene_points_with_normal_item* points_DiamFemur;
	Scene_plane_item* plane_DiamFemur;
	Scene_polylines_item* polyline_DiamFemur;

	double d_CircunCefalica, d_CircunBrazoIzq, d_CircunCintura, d_CircunCadera, d_CircunMusloIzq, d_DiamMuneca, d_DiamFemur, d_talla;
	QString talla_l, pecho_l, cintura_l, cadera_l, brazo_l, wrist_l;
	QString talla_r, pecho_r, cintura_r, cadera_r, brazo_r, wrist_r;

	// TALLA
	Scene_plane_item* plane_talla_right; // plane_item
	// Circunferencia Cefalica
	Scene_points_with_normal_item* points_CircunCefalica_right;
	Scene_plane_item* plane_CircunCefalica_right;
	// Circunferencia brazo Izquierdo
	Scene_plane_item* plane_CircunBrazoIzq_right;
	Scene_points_with_normal_item* points_CircunBrazoIzq_right;
	// Circunferencia Cintura
	Scene_points_with_normal_item* points_CircunCintura_right;
	Scene_plane_item* plane_CircunCintura_right;

	Scene_points_with_normal_item* points_CircunCadera_right;
	Scene_plane_item* plane_CircunCadera_right;

	Scene_points_with_normal_item* points_CircunMusloIzq_right;
	Scene_plane_item* plane_CircunMusloIzq_right;

	Scene_points_with_normal_item* points_DiamMuneca_right;
	Scene_plane_item* plane_DiamMuneca_right;

	Scene_points_with_normal_item* points_DiamFemur_right;
	Scene_plane_item* plane_DiamFemur_right;

	double d_CircunCefalica_right, d_CircunBrazoIzq_right, d_CircunCintura_right, d_CircunCadera_right, d_CircunMusloIzq_right, d_DiamMuneca_right, d_DiamFemur_right, d_talla_right;
	
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
