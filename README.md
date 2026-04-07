# Trackit
Trackit is a lightweight system monitor built using ImGui and OpenGL.
It shows basic system stats like CPU Network stats and memory usage in a simple UI.

## Features
* CPU usage visualization
* Memory usage tracking
* Network stats 
* Clean real time UI using ImGui

## Preview
<img width="800" height="632" alt="image" src="https://github.com/user-attachments/assets/d52c2e4a-1cad-4437-9069-e9a0b1209d7e" />


## Download

Go to the Releases section and download the latest AppImage:
`Trackit-x86_64.AppImage`

## How to run
After downloading:
```
chmod +x Trackit-x86_64.AppImage
./Trackit-x86_64.AppImage
```
Or right click → Properties → allow executing → double click.

## Build from source
Clone the repo:

```
git clone https://github.com/Ashish-331/Trackit.git
cd Trackit/app
```

Compile:
```
g++ main.cpp glad/src/glad.c imgui/*.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp \
-Iglad/include -Iimgui -Iimgui/backends -lglfw -lGL -ldl -o trackit
```

Run:
```
./trackit
```

## Notes
* Linux only (tested on Ubuntu/Mint)
* Requires OpenGL support

## Future ideas

* Disk usage stats
* Better UI layout

---
I am a 2nd Year CS student and made this project just to learn about how the processes are displayed and fetched. i was impressed and fascinated by usign btop/htop and neofetch and thus tried to make something similar. please provide with valuable feedback !!
Made as a learning project.
