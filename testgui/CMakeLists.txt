cmake_minimum_required(VERSION 3.27)
project(testgui)

set(CMAKE_CXX_STANDARD 23)

add_library(imgui
        ImGui/imgui.cpp
        ImGui/imgui_draw.cpp
        ImGui/imgui_demo.cpp
        ImGui/imgui_tables.cpp
        ImGui/imgui_widgets.cpp
        ImGui/imgui_impl_dx9.cpp
        ImGui/imgui_impl_win32.cpp
)

add_executable(photoshop
        BabyPhotoshop/main.cpp
        BabyPhotoshop/gui.cpp
        BabyPhotoshop/gui.h)


target_link_libraries(photoshop PRIVATE imgui d3d9 dwmapi user32 gdi32 kernel32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32)


