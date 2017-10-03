#include "MyClasses.h"

namespace Graph_lib {

const double pi = std::acos(-1);


Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window(xy, w, h, title),
    next_button{Point{x_max()-155, 0}, 80, 20, "Next point", cb_next},
       // [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-70, 0}, 70, 20, "Quit", cb_quit},
       // [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    undo_button{Point{x_max()-155,30}, 70, 20, "Undo", cb_undo},
    next_x{Point{x_max()-310, 0}, 50, 20, "next x:"},
    next_y{Point{x_max()-210, 0}, 50, 20, "next y:"},
    xy_out{Point{100, 0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max()-70, 55}, 70, 20, Menu::vertical, "color"},
    menu_button{Point{x_max()-80, 30}, 80, 20, "color menu", cb_menu}
    {
        attach(next_button);
        attach(quit_button);
        attach(undo_button);
        attach(next_x);
        attach(next_y);
        attach(xy_out);
        xy_out.put("no point");
        attach(lines);

        color_menu.attach(new Button{Point{0,0},0,0,"red", cb_red});
        color_menu.attach(new Button{Point{0,0},0,0,"blue", cb_blue});
        color_menu.attach(new Button{Point{0,0},0,0,"black", cb_black});
        attach(color_menu);
        color_menu.hide();
        attach(menu_button);
        attach(lines);
    }

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address,Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}
void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}
void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}
void Lines_window::quit()
{
    hide();
}
void Lines_window::cb_undo(Address, Address pw)
{
    reference_to<Lines_window>(pw).undo();
}

void Lines_window::undo()
{
    lines.undo();
    redraw();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();
    lines.add(Point{x ,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

Regular_polygon::Regular_polygon(Point pp, int nn, int rr) :
    p{pp}, n{nn}, r{rr}
    {
        if(n > 2 && r > 0)
            {
                for (int i = 0; i < n; ++i)
                {
                    v.push_back(new Point(p.x + get_x(i), p.y - get_y(i)));
                }
            } else  error("wrong input");

    }

 int Regular_polygon::get_x(int i) {
 double rr = r;
 double nn = n;
 double res;
 res = r * std::sin(2*pi/n * i);
 return (int) res;
 }


 int Regular_polygon::get_y(int i) {
 double r = r;
 double n = n;
 double res;
 res = r * std::cos(2*pi/n * i);
 return (int) res;
 }




void Regular_polygon::draw_lines() const {

    if (color().visibility()) {

    for (int i = 0; i < v.size() - 1; ++i)
      fl_line(v[i].x, v[i].y, v[i+1].x, v[i+1].y);

    fl_line(v[v.size()-1].x, v[v.size()-1].y, v[0].x, v[0].y);
    }

}

void Box::draw_lines() const
{
	if (color().visibility())
        {	// edge on top of fill
		fl_color(color().as_int());
		fl_line(point(0).x + r,point(0).y, point(0).x + w - r, point(0).y);
		fl_line(point(0).x,point(0).y + r, point(0).x, point(0).y + h - r);
		fl_line(point(0).x + r,point(0).y + h, point(0).x + w - r, point(0).y + h);
		fl_line(point(0).x + w,point(0).y + r, point(0).x + w, point(0).y + h - r);

		fl_arc(point(0).x, point(0).y, r+r, r+r, 90, 180);
		fl_arc(point(0).x + w - 2*r, point(0).y, r+r, r+r, 0, 90);
		fl_arc(point(0).x + w - 2 * r, point(0).y + h - 2*r, r+r, r+r, 270, 360);
		fl_arc(point(0).x, point(0).y + h - 2*r, r+r, r+r, 180, 270);
        }
}

void Circlefract::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,0, a);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,r+r,r+r,0, a);
	}
}


void Arrow::draw_lines() const
{
    if (color().visibility())
        Shape::draw_lines();
        fl_line(point(4).x, point(4).y, point(1).x, point(1).y);

}

void Arrow::ortho(Point p1, Point p2)
{
    if (p1 != p2)
    {
        op.x = p2.x + 0.2 * (p2.x - p1.x);
        op.y = p2.y + 0.2 * (p2.y - p1.y);

        o1.x = p2.x - 0.2 * (p2.y - p1.y);
        o1.y = p2.y + 0.2 * (p2.x - p1.x);

        o2.x = p2.x + 0.2 * (p2.y - p1.y);
        o2.y = p2.y - 0.2 * (p2.x - p1.x);
    }
}

}
