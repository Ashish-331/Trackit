
# Trackit

A lightweight Linux system monitor built in C++ using Dear ImGui and OpenGL. Reads directly from the `/proc` filesystem — no external monitoring libraries, no daemons. Just the kernel's own data, visualized in real time.

I built this to understand how tools like `htop`, `btop`, and `neofetch` actually work under the hood. Turns out most of it is just reading files in `/proc` and doing the math yourself.

---


## Demo

<!-- Put GIF here -->

<img width="1907" height="1025" alt="Track__it" src="https://github.com/user-attachments/assets/753ee924-3bca-4532-b10b-78c65e44a0f4" />


---

## Features

### CPU
- Real-time usage tracking via `/proc/stat`
- Live scrolling history graph
- Updates every 300ms

### Memory
- Used vs available memory from `/proc/meminfo`
- Progress bar with GB display

### Process Explorer
- Lists all running processes from `/proc/[pid]/`
- Shows PID, name, and RSS memory usage
- Sorted by memory, updates every second
- Capped at 200 processes for performance

### Network Monitoring
- Per-interface RX/TX speeds in KB/s
- Packet counters, error counts, drop counts
- Errors highlighted red, drops highlighted orange
- Session totals (data transferred since app launch)
- Active TCP connection count from `/proc/net/tcp`
- Scrolling download/upload history graphs
- Updates every 500ms

---

## Screenshots

### Main Dashboard
<<<<<<< HEAD

<!-- Put dashboard screenshot here -->

=======
>>>>>>> d2f19d4 (Improved structure)
<img width="1920" height="1080" alt="Track-it-demo" src="https://github.com/user-attachments/assets/d8bf71d9-b48c-415b-a3de-d0f63bf3c11a" />

### Process Explorer
<img width="1047" height="501" alt="Process-tab" src="https://github.com/user-attachments/assets/49d1ee24-8a92-4be9-9c84-c600b78aba3a" />

### Network Monitor
<img width="847" height="455" alt="Network" src="https://github.com/user-attachments/assets/0738e146-7236-4faf-a379-d50139e9e08a" />

<<<<<<< HEAD
<img width="1047" height="501" alt="Process-tab" src="https://github.com/user-attachments/assets/49d1ee24-8a92-4be9-9c84-c600b78aba3a" />

=======
---
>>>>>>> d2f19d4 (Improved structure)

## How It Works

Trackit reads kernel-exposed data directly from the `/proc` filesystem:

<<<<<<< HEAD
<img width="847" height="455" alt="Network" src="https://github.com/user-attachments/assets/0738e146-7236-4faf-a379-d50139e9e08a" />

=======
| Source | Data |
|---|---|
| `/proc/stat` | CPU ticks (user, nice, system, idle) |
| `/proc/meminfo` | MemTotal, MemAvailable |
| `/proc/net/dev` | Per-interface bytes, packets, errors, drops |
| `/proc/net/tcp` | Active TCP connection entries |
| `/proc/[pid]/comm` | Process name |
| `/proc/[pid]/status` | VmRSS (resident memory) |

CPU usage is calculated as `delta_active / delta_total` between polling intervals. Network speed is `byte_diff / elapsed_seconds`, computed per interface and summed for the aggregate view.

---

## Build

**Dependencies:** GLFW, OpenGL, libdl (standard on most Linux distros)

```bash
git clone https://github.com/Ashish-331/Trackit.git
cd Trackit
bash build.sh
./trackit
```

The build script compiles `main.cpp` alongside the vendored glad and ImGui sources in one shot — no CMake, no Make.
>>>>>>> d2f19d4 (Improved structure)

---

## Download

Grab the prebuilt AppImage from the [Releases](../../releases) section:

```bash
chmod +x Trackit-x86_64.AppImage
./Trackit-x86_64.AppImage
```

---

## Tech Stack

- C++
- Dear ImGui
- OpenGL 3.3 + GLAD
- GLFW
- Linux `/proc` filesystem

---

## What's Next

- Per-process CPU usage
- Disk I/O monitoring
- Multi-core CPU breakdown
- Process search/filter
- Split into proper modules (network, process, cpu as separate translation units)

---

<<<<<<< HEAD
## About

I'm a 2nd year CS student and built this project to better understand how Linux exposes system information and how monitoring tools visualize that data.

Tools like `btop`, `htop`, and `neofetch` were a big inspiration, and Trackit started as an attempt to explore those concepts by building my own version from scratch.

Feedback and suggestions are always welcome.

---

Built to explore Linux system programming, real-time monitoring, and desktop UI development in C++.
=======
Built this as a 2nd year CS student to dig into how Linux exposes system internals. Most of it came from reading kernel docs and reverse-engineering what `btop` was doing. Feedback is welcome.
>>>>>>> d2f19d4 (Improved structure)
