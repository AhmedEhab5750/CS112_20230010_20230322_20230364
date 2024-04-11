#include "gui.h"
#include <thread>
#include <windows.h> // For Win32 functions
#include <d3d9.h>    // For Direct3D functions
#include <dwmapi.h>  // For DWM functions
int main() {
    gui::CreateHWindow("Bab", "Menu");
    gui::CreateDevice();
    gui::CreatImGui();

    while(gui::exit){
        gui::BeginRender();
        gui::Render();
        gui::EndRender();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    gui::DestroyImGui();
    gui::DestroyDevice();
    gui::DestroyHWindow();

    return 0;
}
