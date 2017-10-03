/*
#include "Simple_window.h"
#include "Graph.h"

int main() {

    using namespace Graph_lib;

    Simple_window win{Point{100,100}, 600, 400, "Canvas"};

    Rectangle r1{{50,50}, {250,250}};
    Rectangle r2{{75,75}, {275,275}};
    Lines deep;
    deep.add({50,50},{75,75});
    deep.add({50,250},{75,275});
    deep.add({250,50},{275,75});
    deep.add({250,250},{275,275});

    win.attach(r1);
    win.attach(r2);
    win.attach(deep);
    win.wait_for_button();

}
*/
