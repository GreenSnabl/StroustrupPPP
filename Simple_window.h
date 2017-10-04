#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include "MyClasses.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title);

    bool wait_for_button(); // simple event loop

private:
    Button next_button;     // the "next" button
    bool button_pushed;     // implementation detail

    static void cb_next(Address, Address); // callback for next_button
    void next();            // action to be done when next_button is pressed

};

//------------------------------------------------------------------------------

struct My_window : Simple_window {
    My_window(Point xy, int w, int h, const string& title);
private:
    Button quit_button;

    static void cb_quit(Address, Address pw) { reference_to<My_window>(pw).quit(); }
    void quit() { hide(); }
};

struct Button_window : My_window {
    Button_window(Point xy, int w, int h, const string& title);
private:
    // widgets
    Menu menu1;
    Menu menu2;
    Menu menu3;
    Menu menu4;
    Out_box xy_out;

    // actions invoked by callback: relabel button, print coordinates
    void reset_labels();    // helper function
    void action(Button& b);
    void action11() { action(menu1.selection[0]); }
    void action12() { action(menu1.selection[1]); }
    void action13() { action(menu1.selection[2]); }
    void action14() { action(menu1.selection[3]); }
    void action21() { action(menu2.selection[0]); }
    void action22() { action(menu2.selection[1]); }
    void action23() { action(menu2.selection[2]); }
    void action24() { action(menu2.selection[3]); }
    void action31() { action(menu3.selection[0]); }
    void action32() { action(menu3.selection[1]); }
    void action33() { action(menu3.selection[2]); }
    void action34() { action(menu3.selection[3]); }
    void action41() { action(menu4.selection[0]); }
    void action42() { action(menu4.selection[1]); }
    void action43() { action(menu4.selection[2]); }
    void action44() { action(menu4.selection[3]); }

    // callback functions
    static void cb_action11(Address, Address pw) { reference_to<Button_window>(pw).action11(); }
    static void cb_action12(Address, Address pw) { reference_to<Button_window>(pw).action12(); }
    static void cb_action13(Address, Address pw) { reference_to<Button_window>(pw).action13(); }
    static void cb_action14(Address, Address pw) { reference_to<Button_window>(pw).action14(); }
    static void cb_action21(Address, Address pw) { reference_to<Button_window>(pw).action21(); }
    static void cb_action22(Address, Address pw) { reference_to<Button_window>(pw).action22(); }
    static void cb_action23(Address, Address pw) { reference_to<Button_window>(pw).action23(); }
    static void cb_action24(Address, Address pw) { reference_to<Button_window>(pw).action24(); }
    static void cb_action31(Address, Address pw) { reference_to<Button_window>(pw).action31(); }
    static void cb_action32(Address, Address pw) { reference_to<Button_window>(pw).action32(); }
    static void cb_action33(Address, Address pw) { reference_to<Button_window>(pw).action33(); }
    static void cb_action34(Address, Address pw) { reference_to<Button_window>(pw).action34(); }
    static void cb_action41(Address, Address pw) { reference_to<Button_window>(pw).action41(); }
    static void cb_action42(Address, Address pw) { reference_to<Button_window>(pw).action42(); }
    static void cb_action43(Address, Address pw) { reference_to<Button_window>(pw).action43(); }
    static void cb_action44(Address, Address pw) { reference_to<Button_window>(pw).action44(); }
};

//------------------------------------------------------------------------------

struct Item_window : My_window {
    Item_window(Point xy, int w, int h, const string& title);

private:

    Menu item_menu;
    In_box in_x;
    In_box in_y;
    Vector_ref<Shape> items;

    void draw_circle();
    void draw_triangle();
    void draw_square();
    void draw_hexagon();

    static void cb_drawc(Address, Address pw) {reference_to<Item_window>(pw).draw_circle();}
    static void cb_drawt(Address, Address pw) {reference_to<Item_window>(pw).draw_triangle();}
    static void cb_draws(Address, Address pw) {reference_to<Item_window>(pw).draw_square();}
    static void cb_drawh(Address, Address pw) {reference_to<Item_window>(pw).draw_hexagon();}

};

//-----------------------------------------------------------------------------


#endif
