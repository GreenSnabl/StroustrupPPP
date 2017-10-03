/*#include "Simple_window.h"
#include "Graph.h"
#include "MyClasses.h"
#include "std_lib_facilities.h"



double one(double) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}

int main() {

using namespace Graph_lib;

constexpr int xmax = 600;
constexpr int ymax = 400;

constexpr int x_orig = xmax/2;
constexpr int y_orig = ymax/2;

constexpr int r_min = -10;
constexpr int r_max = 11;

constexpr int n_points = 400;

constexpr int x_scale = 30;
constexpr int y_scale = 30;

constexpr int xlength = xmax-40;
constexpr int ylength = ymax-40;


Simple_window win(Point{20, 20}, 600, 400, "Canvas");


Ellipse e({300, 200}, 250, 150);

Axis ax(Axis::x, Point{20, y_orig},
         xlength, xlength/x_scale, "one notch == 1");
Axis ay(Axis::y, Point{x_orig, ylength + 20},
        ylength, ylength/y_scale, "one notch == 1");

ax.notches.set_color(Color::white);



Function s{one, r_min, r_max, Point{x_orig, y_orig}, n_points, x_scale, y_scale };
Function s2 {slope, r_min, r_max, Point{x_orig, y_orig}, n_points, x_scale, y_scale };
Function s3 {square, r_min,r_max, Point{x_orig, y_orig}, n_points, x_scale, y_scale };
Function s4 {log, r_min, r_max, Point{x_orig, y_orig}, n_points, x_scale, y_scale};
Function s6 {sqrt, r_min, r_max, Point{x_orig, y_orig}, n_points, x_scale, y_scale};

win.attach(ax);
win.attach(ay);


win.attach(s);
win.attach(s2);
win.attach(s3);
win.attach(e);
win.attach(s4);
win.attach(s6);


win.wait_for_button();



int main()
try {
    Lines_window win{Point{100, 100}, 600, 400, "lines"};
    return gui_main();


    }
    catch(exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Some exception\n";
        return 2;
    }
*/
