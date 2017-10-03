#include "Simple_window.h"
#include "Graph.h"


int main() {

    using namespace Graph_lib;

    Simple_window win{Point{100,100}, 400, 400, "color chart"};


    Arrow a(Point(440, 50), Point(200,200));



/*
    Vector_ref<Rectangle> vr;

    for(int i = 0; i<16; ++i)
      for(int j = 0; j<16;++j) {
        vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
        vr[vr.size()-1].set_fill_color(Color{i*16+j});
      //  vr[vr.size()-1].set_color(Color::invisible);                  // grid on / off
        win.attach(vr[vr.size()-1]);

    }*/

    win.attach(a);
    win.wait_for_button();


}
