# Trackit

Trackit is a lightweight system monitor built using ImGui and OpenGL.
It displays basic system stats like CPU, memory, and network usage in a simple real-time UI.

## Features

* CPU usage visualization
* Memory usage tracking
* Network statistics
* Clean real-time UI using ImGui

## Preview

<img width="800" height="632" alt="Trackit UI" src="https://github.com/user-attachments/assets/d52c2e4a-1cad-4437-9069-e9a0b1209d7e" />

---

## Download

Go to the **Releases** section and download:

`Trackit-x86_64.AppImage`

---

## Run

```bash
chmod +x Trackit-x86_64.AppImage
./Trackit-x86_64.AppImage
```

Or:

* Right click → Properties
* Enable “Allow executing file as program”
* Double click

---

## Build from Source

```bash
git clone https://github.com/Ashish-331/Trackit.git
cd Trackit
./build.sh
```

Run:

```bash
./trackit
```

---

## Notes

* Linux only (tested on Ubuntu / Mint)
* Requires OpenGL support

---

## Future Ideas

* Disk usage stats
* Improved UI layout

---

## About

I’m a 2nd year CS student and built this project to understand how system stats are fetched and visualized.

Tools like `btop`, `htop`, and `neofetch` really inspired me, and I wanted to try building something similar from scratch.

If you have any feedback or suggestions, I’d really appreciate it.

---

Made as a learning project.
