
# 🐝 BeeHive3D Documentation

## Table of Contents
1. [Project Overview](#project-overview)  
2. [Features](#features)  
3. [Project Structure](#project-structure)  
4. [Dependencies](#dependencies)  
5. [Installation & Compilation](#installation--compilation)  
6. [Controls](#controls)  
7. [Code Highlights](#code-highlights)  
8. [Future Improvements](#future-improvements)  

---

## Project Overview

**BeeHive3D** is a C++ OpenGL project that simulates a **3D beehive with bees flying around it**.  

- Uses **OpenGL 3.3 Core Profile** for rendering.  
- Implements a **FPS-style camera** with mouse look.  
- Hive is generated procedurally using **hexagonal prisms**.  
- Bees are animated using simple **circular/orbiting trajectories** around the hive.  
- Lightweight shaders provide **color-based lighting**.

The project demonstrates **3D rendering, animation, and interactive camera control** in C++ with GLFW, GLAD, and GLM.

---

## Features

- 3D procedurally generated beehive  
- 10 animated bees flying around the hive  
- Interactive camera with **WASD movement + mouse look**  
- Basic lighting and shading  
- Scalable design to add textures or models  

---

## Project Structure

BeeHive3D/
│
├── shaders/
│ ├── vertex.glsl # Vertex shader for MVP transformations
│ └── fragment.glsl # Fragment shader for color and lighting
│
├── src/
│ ├── main.cpp # Main program: window, render loop, camera, bees
│ ├── hive.cpp # Procedural hive geometry generation
│ ├── bee.cpp # Bee animation logic
│ └── camera.cpp # FPS camera implementation
│
├── include/
│ ├── shader.h # Shader helper class
│ └── camera.h # Camera class header
│
├── glad.c # GLAD OpenGL loader
├── include/glad/ # GLAD header files
└── assets/
├── bee.obj # Optional bee model
└── hive_texture.jpg # Hive texture image


---

## Dependencies

- **GLFW**: Window creation & input handling  
- **GLAD**: OpenGL function loader  
- **GLM**: Mathematics library for vectors and matrices  
- **OpenGL 3.3 Core**  

**MSYS2 Installation Commands:**

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-glfw mingw-w64-x86_64-glm
```

## Installation & Compilation

Open MSYS2 MinGW64 terminal.

Navigate to project root:

```bash 
cd /c/Users/YourUsername/Desktop/BeeHive3D
```
```bash
g++ src/main.cpp src/hive.cpp src/bee.cpp src/camera.cpp src/shader.cpp glad.c \
    -Iinclude \
    -lglfw3 -lopengl32 -lgdi32 \
    -o BeeHive3D
```

```bash
./BeeHive3D
```

![Beehive](https://res.cloudinary.com/dhyii4oiw/image/upload/v1769095962/Screenshot_2026-01-22_204806_uj8xlv.png)
![Beehive Video](https://res.cloudinary.com/dhyii4oiw/video/upload/v1769095987/Screen_Recording_2026-01-22_204712_qiw8ef.mp4)