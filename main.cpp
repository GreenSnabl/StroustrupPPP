#include "Simple_window.h"
#include "Graph.h"
#include "MyClasses.h"
#include "GUI.h"

#include "std_lib_facilities.h"


int main ()
try {
    Lines_window win(Point{100, 100}, 600, 400, "lines");
    return gui_main();
} catch (exception &e)
{
    cerr << "exception: " << e.what() << "\n";
    return 1;
} catch (...) {
    cout << "some exception" << "\n";
    return 2;
}
