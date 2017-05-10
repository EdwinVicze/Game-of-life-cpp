#include "window.hpp"
#include <windows.h>

int main(){
    FreeConsole();

    Window window(800, 600, "GOLAD");
    window.run();

    return 0;
}
