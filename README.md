# 🧊 CUBE3D

Project developed as part of our Common Core at 42 school, in collaboration with **Naankour**.

## Description

**CUBE3D** is a simple 3D rendering engine using **raycasting**, inspired by *Wolfenstein 3D*.  
It generates a pseudo-3D first-person view from a 2D map — think of it as 2.5D.  
Developed in **C** using the **MiniLibX** library.

## Features

- Real-time rendering using raycasting

<p align="center">
  <img src="Readme/game.gif" alt="Raycasting Demo" width="50%">
</p>

- `.cub` file parsing (map + texture paths)

- Player movement and rotation

- Wall texture mapping

<p align="center">
  <img src="Readme/door.gif" alt="Door Animation" width="50%">
</p>

- Optional minimap

<p align="center">
  <img src="Readme/minimap.gif" alt="Minimap Demo" width="20%">
</p>

## Technologies

- C  
- MiniLibX  
- Makefile

## Build & Run

```bash
make minilibx
make bonus
./cube3D map/[select_map]
