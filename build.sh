g++ src/main.cpp glad/src/glad.c imgui/*.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp -Iglad/include -Iimgui -Iimgui/backends -lglfw -lGL -ldl -o trackit
