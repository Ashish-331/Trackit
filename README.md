
# Trackit

Trackit is a lightweight Linux system monitor built using Dear ImGui and OpenGL.

It displays system information in real time by reading data directly from the Linux `/proc` filesystem. The goal of the project was to understand how tools like `htop`, `btop`, and `neofetch` work under the hood and try building something similar from scratch.

---

## Demo

<!-- Put GIF here -->

<img width="1907" height="1025" alt="Track__it" src="https://github.com/user-attachments/assets/753ee924-3bca-4532-b10b-78c65e44a0f4" />


---

## Features

### CPU Monitoring

* Real-time CPU usage tracking
* Live CPU history graph
* Percentage-based visualization

### Memory Monitoring

* System memory usage tracking
* Used vs available memory display
* Live memory utilization bar

### Process Explorer

* Running process list
* Process IDs (PID)
* Process names
* Per-process RAM usage
* Memory-based sorting

### Network Monitoring

* Real-time upload speed
* Real-time download speed
* Historical traffic graphs
* Per-interface statistics
* Packet counters
* Error monitoring
* Packet drop monitoring
* Active TCP connection count

---

## Screenshots

### Main Dashboard

<!-- Put dashboard screenshot here -->

<img width="1920" height="1080" alt="Track-it-demo" src="https://github.com/user-attachments/assets/d8bf71d9-b48c-415b-a3de-d0f63bf3c11a" />

### Process Explorer

<!-- Put process screenshot here -->

<img width="1047" height="501" alt="Process-tab" src="https://github.com/user-attachments/assets/49d1ee24-8a92-4be9-9c84-c600b78aba3a" />


### Network Monitoring

<!-- Put network screenshot here -->

<img width="847" height="455" alt="Network" src="https://github.com/user-attachments/assets/0738e146-7236-4faf-a379-d50139e9e08a" />


---

## Download

Download the latest release from the Releases section.

Included binary:

`Trackit-x86_64.AppImage`

---

## Run

```bash
chmod +x Trackit-x86_64.AppImage
./Trackit-x86_64.AppImage
```

Or:

* Right click → Properties
* Enable "Allow executing file as program"
* Double click

---

## Build From Source

```bash
git clone https://github.com/Ashish-331/Trackit.git
cd Trackit
bash build.sh
```

Run:

```bash
./trackit
```

---

## How It Works

Trackit gathers information directly from Linux system files:

* `/proc/stat` → CPU statistics
* `/proc/meminfo` → Memory statistics
* `/proc/net/dev` → Network traffic
* `/proc/net/tcp` → TCP connections
* `/proc/[pid]/comm` → Process names
* `/proc/[pid]/status` → Process memory usage

The collected data is rendered through a custom Dear ImGui dashboard and updated in real time.

---

## Tech Stack

* C++
* Dear ImGui
* OpenGL
* GLFW
* Linux `/proc` filesystem

---

## Future Ideas

* Per-process CPU usage
* Disk usage monitoring
* Multi-core CPU visualization
* Process search and filtering
* Custom themes

---

## About

I'm a 2nd year CS student and built this project to better understand how Linux exposes system information and how monitoring tools visualize that data.

Tools like `btop`, `htop`, and `neofetch` were a big inspiration, and Trackit started as an attempt to explore those concepts by building my own version from scratch.

Feedback and suggestions are always welcome.

---

Built to explore Linux system programming, real-time monitoring, and desktop UI development in C++.
