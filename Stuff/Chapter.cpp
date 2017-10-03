/*#include "Simple_window.h"
#include "Graph.h"

int main ()
{

 using namespace Graph_lib;

 Simple_window win(Point{100, 100}, 600, 400, "Canvas");

 Axis xa{Axis::x, Point{20,350}, 280, 20, "x axis"};
 Axis ya{Axis::y, Point{20,350}, 280, 20, "y axis"};
 ya.set_color(Color::cyan);

 Function sine {sin, 0, 100, Point{20,300}, 200, 50, 50};

 Polygon poly;
 poly.add(Point{300,200});
 poly.add(Point{350,100});
 poly.add(Point{400,200});
 poly.set_color(Color::red);
 poly.set_style(Line_style::dash);


 Rectangle r{Point{200,200}, 100, 50};
 r.set_fill_color(Color::yellow);




 Closed_polyline poly_rect;
 poly_rect.add(Point{100,50});
 poly_rect.add(Point{200,50});
 poly_rect.add(Point{200,100});
 poly_rect.add(Point{100,100});
 poly_rect.add(Point{75, 75});
 poly_rect.set_fill_color(Color::green);
 poly_rect.set_style(Line_style(Line_style::dash, 2));

 Text t{Point{150,150}, "Hello, graphical world!"};
 t.set_font(Graph_lib::Font::times_bold);
 t.set_font_size(20);

 Image img {Point{50, 200}, "cat.jpg"};
 img.set_mask(Point{400, 400}, 100, 100);

 Circle c{Point{100,200},50};
 Ellipse e{Point{100,200}, 75, 25};
 e.set_color(Color::dark_red);
 Mark m {Point{100, 200}, 'x'};

 ostringstream oss;
 oss << "screen size: " << x_max() << "*" << y_max()
     << "; window size: "<< win.x_max() << "*" << win.y_max();
 Text sizes{Point{100,20}, oss.str()};

 Image img2{Point{200,200}, "ei.JPG"};
 img2.set_mask(Point{40,40}, 100, 100);

 win.attach(c);
 win.attach(e);
 win.attach(m);
 win.attach(sizes);
 win.attach(img2);
 win.attach(img);
 win.attach(t);
 win.attach(poly_rect);
 win.attach(r);
 win.attach(poly);
 win.attach(ya);
 win.attach(xa);
 win.attach(sine);


 win.set_label("Canvas #12");
 win.wait_for_button();

}
*/
