
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
#include "Simple_window.h"

using namespace Graph_lib;
//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 0
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
    reference_to<Simple_window>(pw).next();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------

My_window::My_window(Point xy, int w, int h, const string& title)
    :Simple_window(xy,w,h,title),
    quit_button(Point(x_max()-70,30),70,20,"Quit",cb_quit)
{
    attach(quit_button);
}

//------------------------------------------------------------------------------

Item_window::Item_window(Point xy, int w, int h, const string& title)
    :My_window(xy, w, h, title),
    item_menu(Point{x_max()-70, 60},70, 20, Menu::vertical, "Item menu"),
    in_x(Point(x_max() - 150, 0), 70, 20, "x"),
    in_y(Point(x_max() - 225, 0), 70, 20, "y")

{
    item_menu.attach(new Button(Point{0,0},0,0,"Circle",cb_drawc));
    item_menu.attach(new Button(Point{0,0},0,0,"Circle",cb_drawt));
    item_menu.attach(new Button(Point{0,0},0,0,"Circle",cb_draws));
    item_menu.attach(new Button(Point{0,0},0,0,"Circle",cb_drawh));
    attach(item_menu);
    attach(in_x);
    attach(in_y);
}

void Item_window::draw_circle()
{
    int x = in_x.get_int();
    int y = in_y.get_int();
    items.push_back(new Circle(Point{x,y}, 50));
    attach(items[items.size()-1]);
}

void Item_window::draw_triangle()
{
    int x = in_x.get_int();
    int y = in_y.get_int();
    items.push_back(new Regular_polygon(Point{x,y}, 3, 50));
    attach(items[items.size()-1]);
}

void Item_window::draw_square()
{
    int x = in_x.get_int();
    int y = in_y.get_int();
    items.push_back(new Regular_polygon(Point{x,y}, 4, 50));
    attach(items[items.size()-1]);
}

void Item_window::draw_hexagon()
{
    int x = in_x.get_int();
    int y = in_y.get_int();
    items.push_back(new Regular_polygon(Point{x,y}, 6, 50));
    attach(items[items.size()-1]);
}


Button_window::Button_window(Point xy, int w, int h, const string& title)
    :My_window(xy,w,h,title),
    menu1(Point(0,0),100,100,Menu::vertical,"menu1"),
    menu2(Point(100,0),100,100,Menu::vertical,"menu2"),
    menu3(Point(200,0),100,100,Menu::vertical,"menu3"),
    menu4(Point(300,0),100,100,Menu::vertical,"menu4"),
    xy_out(Point(x_max()-70,60),70,20,"(x,y)")
{
    menu1.attach(new Button(Point(0,0),0,0,"1-1",cb_action11));
    menu1.attach(new Button(Point(0,0),0,0,"1-2",cb_action12));
    menu1.attach(new Button(Point(0,0),0,0,"1-3",cb_action13));
    menu1.attach(new Button(Point(0,0),0,0,"1-4",cb_action14));
    attach(menu1);
    menu2.attach(new Button(Point(0,0),0,0,"2-1",cb_action21));
    menu2.attach(new Button(Point(0,0),0,0,"2-2",cb_action22));
    menu2.attach(new Button(Point(0,0),0,0,"2-3",cb_action23));
    menu2.attach(new Button(Point(0,0),0,0,"2-4",cb_action24));
    attach(menu2);
    menu3.attach(new Button(Point(0,0),0,0,"3-1",cb_action31));
    menu3.attach(new Button(Point(0,0),0,0,"3-2",cb_action32));
    menu3.attach(new Button(Point(0,0),0,0,"3-3",cb_action33));
    menu3.attach(new Button(Point(0,0),0,0,"3-4",cb_action34));
    attach(menu3);
    menu4.attach(new Button(Point(0,0),0,0,"4-1",cb_action41));
    menu4.attach(new Button(Point(0,0),0,0,"4-2",cb_action42));
    menu4.attach(new Button(Point(0,0),0,0,"4-3",cb_action43));
    menu4.attach(new Button(Point(0,0),0,0,"4-4",cb_action44));
    attach(menu4);
    attach(xy_out);
    xy_out.put("no point");
}

//------------------------------------------------------------------------------

void Button_window::reset_labels()
{
    for (int i = 0; i<4; ++i) {
        menu1.selection[i].label = "1-" + to_string(i+1);
        menu2.selection[i].label = "2-" + to_string(i+1);
        menu3.selection[i].label = "3-" + to_string(i+1);
        menu4.selection[i].label = "4-" + to_string(i+1);
    }
    redraw();
}

//------------------------------------------------------------------------------

void Button_window::action(Button& b)
{
    reset_labels();
    b.label = "CLICKED";
    ostringstream os;
    os << '(' << b.loc.x << ',' << b.loc.y << ')';
    xy_out.put(os.str());
}



