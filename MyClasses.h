#ifndef MY_CLASSES.H
#define MY_CLASSES.H
#include <sstream>
#include "Graph.h"
#include "GUI.h"

namespace Graph_lib {


struct Lines_window : Window {

    Lines_window(Point xy, int w, int h, const string& title);

private:

    Open_polyline lines;


    Button next_button;
    Button quit_button;
    Button undo_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button menu_button;


    void change(Color c) {lines.set_color(c);}


    void hide_menu() {color_menu.hide(); menu_button.show();}


    void red_pressed() {change(Color::red); hide_menu();}
    void blue_pressed() {change(Color::blue); hide_menu();}
    void black_pressed() {change(Color::black); hide_menu();}
    void menu_pressed() {menu_button.hide(); color_menu.show();}
    void undo();
    void next();
    void quit();

    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_undo(Address, Address);
};


struct Regular_polygon : Shape {

    Regular_polygon(Point pp, int nn, int rr);
    void draw_lines() const;
    int get_x(int i);
    int get_y(int i);


private:
    Vector_ref<Point> v;
    Point p;
    int n;
    int r;

};


struct Box : Shape {

    Box(Point xy, int ww, int hh, int rr)
    : w{ww}, h{hh}, r{rr}
    {
        if(w <= 0 || h <= 0) error("side <= 0");
        if(ww <= 2*r || hh <= 2 * r) error("not a box");
        add(xy);
    }

    void draw_lines() const;

    void set_radius(int rr) { r = rr; }
    int radius(int rr) { return r; }

private:
    int w;
    int h;
    int r;
};

struct Arrow : Shape {
    Arrow(Point p1, Point p2)
    {
    add(p1);
    add(p2);
    ortho(p1, p2);
    add(o1);
    add(op);
    add(o2);
    }
    void draw_lines() const;
    void ortho(Point p1, Point p2);

private:

    Point op;
    Point o1;
    Point o2;
};



struct Circlefract : Shape {
    Circlefract(Point p, int rr, double arc)            // Neu hinzugefügt
    :r{rr}, a{arc}
    {
        add(Point{p.x - r, p.y - r});
    }
    Point center() const { return { point(0).x + r, point(0).y + r }; }

	void set_radius(int rr) { r=rr; }
	int radius() const { return r; }

    void draw_lines() const;

private:
    int r;
    double a;
};



}
#endif // MY_CLASSES



