# cub3D

## Table of Contents

- [Project Overview](#project-overview)
- [Summary](#summary)
- [Project Goals](#project-goals)
- [Project Requirements](#project-requirements)
- [Screenshots and Demos of our project](#screenshots-and-demos-of-our-project)
- [Team Development Steps](#team-development-steps)
  - [1. Project Setup](#1-project-setup)
  - [2. Parsing Configuration File](#2-parsing-configuration-file)
  - [3. Initialize Graphics](#3-initialize-graphics)
  - [4. Raycasting Engine](#4-raycasting-engine)
  - [5. Texture Mapping](#5-texture-mapping)
  - [6. Player Movement and Controls](#6-player-movement-and-controls)
  - [7. Rendering Game World](#7-rendering-game-world)
  - [8. Error Handling and Cleanup](#8-error-handling-and-cleanup)
  - [9. Optimization and Refactoring](#9-optimization-and-refactoring)
  - [10. Bonus Features (Optional)](#10-bonus-features-optional)
- [Project Structure](#project-structure)
- [I. Project Setup](#i-project-setup)
  - [Step 1: Setup](#step-1-setup)
  - [Step 2: Create Files](#step-2-create-files)
- [II. Parsing Configuration File](#ii-parsing-configuration-file)
  - [Map requirements](#map-requirements)
  - [Prsing and Storing the Configuration File](#prsing-and-storing-the-configuration-file)
- [III. Initialize Graphics](#iii-initialize-graphics)
- [Resources](#resources)
  - [Video resources](#video-resources)


## Project Overview

Welcome to our cub3d project! As a team, we'll be diving into the exciting world of raycasting and basic 3D graphics programming. Our main goal is to create a simple 3D maze game from scratch using raycasting techniques.

## Summary

This project is inspired by the world-famous [Wolfenstein 3D game](https://en.wikipedia.org/wiki/Wolfenstein_3D), which was the first FPS ever. It is a remarkable technique to explore, and a great opportunity to create a game with a good design and a nice user interface.

![cool-guys-1992-small](https://github.com/zelhajou/42-cub3D/assets/39954629/e53038ee-d9ed-43fa-8f58-44ee63a5ede3)

Developed by [id Software](https://en.wikipedia.org/wiki/Id_Software) and published by [Apogee Software](https://en.wikipedia.org/wiki/Apogee_Software), Wolfenstein 3D was released in 1992. It was a revolutionary game that popularized the FPS genre and helped establish the PC as a gaming platform.

[Playable Wolfenstein 3D](http://users.atw.hu/wolf3d/)

## Project Goals

1. **Raycasting Engine**: Develop a raycasting engine to render a 3D world from a first-person perspective.
2. **Parsing Configuration File**: Read and parse a configuration file (.cub) to define our game settings, including map layout, textures, and other parameters.
3. **Texture Mapping**: Apply textures to walls and potentially the floor and ceiling to enhance our game's visual appearance.
4. **Player Movement and Controls**: Implement controls to allow the player to move within the 3D world, including basic movement (e.g., forward, backward, strafing) and rotation.
5. **Basic Game Mechanics**: Create a playable game where the player can navigate through a maze-like environment, interact with objects, and complete objectives.
6. **Error Handling and Optimization**: Implement robust error handling to handle invalid input and prevent crashes. Optimize our code for performance to ensure smooth gameplay.

## Project Requirements

- **Language**: We'll be using C for this project.
- **Libraries**: We can use standard libraries like `math`. External libraries like `minilibx` are allowed for graphics rendering.
- **Map Configuration**: Our game should read a map configuration file (.cub) that defines game settings, including map layout, textures, colors, and more.
- **Graphics**: The game must render a 3D perspective view of the game world using raycasting techniques. Textures should be applied to walls to enhance the visual appearance.
- **Controls**: Implement controls to allow the player to move and navigate within the 3D world using keyboard input.
- **Bonus Features**: While not required, implementing additional features like a minimap, HUD (Heads-Up Display), or more complex game mechanics can earn us extra points.

## Screenshots and Demos of our project

| | |
|:-------------------------:|:-------------------------:|
| <img width="1230" alt="Screen Shot 2024-05-09 at 12 22 47 PM" src="https://github.com/zelhajou/42-cub3D/assets/39954629/e4879374-df66-42eb-9b81-9eac22a27089"> | <img width="1245" alt="Screen Shot 2024-05-09 at 12 24 31 PM" src="https://github.com/zelhajou/42-cub3D/assets/39954629/319554ac-ebe6-4dd3-91c5-495c857f407b">
| <img width="1346" alt="Screen Shot 2024-05-09 at 12 47 45 PM" src="https://github.com/zelhajou/42-cub3D/assets/39954629/f60b06a5-2171-4a9a-b132-85832746dab7"> | <img width="1288" alt="Screen Shot 2024-05-09 at 12 40 14 PM" src="https://github.com/zelhajou/42-cub3D/assets/39954629/ca7bd27b-4f3f-4b9b-aa6f-3cf9c8537031"> |

https://github.com/zelhajou/42-cub3D/assets/39954629/5c64d881-2734-4e40-95aa-60fd97a8639a

## Team Development Steps

As a team, we'll be tackling the cub3d project in a systematic manner to ensure a successful outcome. Here's our proposed development roadmap:

### 1. Project Setup

Set up the project repository, establish communication channels, and assign roles.

- [x] **Create Repository**: Set up a Git repository for the project.
- [x] **Establish Communication**: Choose communication tools (Discord) for team collaboration.
- [x] **Assign Roles**: Define roles and responsibilities for each team member.

### 2. Parsing Configuration File

Implement the code to read and parse the configuration file (.cub) to extract game settings.

- [x] **Read File**: Open and read the .cub configuration file.
- [x] **Validate Data**: Check for valid map settings, resolution, textures, etc.
- [x] **Parse Data**: Extract and store relevant information from the configuration file.

### 3. Initialize Graphics

Set up the graphics rendering engine using the `minilibx` library.

- [x] **Initialize Minilibx**: Set up the Minilibx library for graphics rendering.
- [x] **Create Window**: Create a window for rendering the game.
- [x] **Setup Buffer**: Set up a buffer for rendering pixels to the window.

### 4. Raycasting Engine

Develop the raycasting engine to render a 3D perspective view of the game world.

- [x] **Initialize Ray**: Start with the player's position and direction.
- [x] **Cast Rays**: Cast rays from the player's position to calculate distances to walls.
- [x] **Calculate Wall Strips**: Determine the height and texture of each wall strip to draw.

### 5. Texture Mapping

Apply textures to walls to enhance the visual appearance of the game.

- [x] **Load Textures**: Load wall and sprite textures from files.
- [x] **Implement Texture Mapping**: Apply textures to the rendered walls.

### 6. Player Movement and Controls

Implement controls to allow the player to move and navigate within the 3D world.

- [x] **Handle Input**: Implement controls for player movement (e.g., WASD for movement, arrow keys for rotation).
- [x] **Update Player Position**: Update the player's position based on input and collision detection.

### 7. Rendering Game World

Render the game world using the raycasting results and textures.

- [x] **Draw Walls**: Render the walls of the 3D world using the raycasting results.
- [x] **Draw Floor and Ceiling**: Render the floor and ceiling of the 3D world.
- [ ] **Draw Sprites**: Implement sprite rendering if necessary.

### 8. Error Handling and Cleanup

Implement error handling to prevent crashes and ensure a smooth user experience.

- [x] **Error Checks**: Implement error handling to catch and handle any runtime errors.
- [x] **Memory Cleanup**: Free allocated memory and resources.
- [x] **Close Window**: Properly close the graphics window when exiting the game.

### 9. Optimization and Refactoring

Optimize the code for performance and refactor as needed for better readability.

- [x] **Optimize Raycasting**: Improve raycasting performance if necessary.
- [x] **Refactor Code**: Clean up and organize the code for better readability and maintainability.

### 10. Bonus Features (Optional)

Implement additional features to enhance the game experience and earn extra points.

- [x] **Add Features**: Implement additional features like a minimap, HUD, or more complex game mechanics.
- [x] **Testing**: Thoroughly test the game to ensure all features work as expected.

## Project Structure

The project will be structured as follows:

```
cub3d/
│
└── src                        # Source code files
│   ├── parsing                # Functions for parsing the configuration file
│   │   ├── color
│   │   ├── config
│   │   ├── map
│   │   └── texture
│   ├── rendering               # Functions for rendering the 3D world
│   └── utils                   # Utility functions
│
├── includes                    # Header files
│   ├── cub3d.h
│   └── engine.h
│
├── assets/
│   ├── textures/               # Directory for storing texture files (.xpm or .png)
│   └── maps/                   # Directory for storing map configuration files (.cub)
│
├── libft/                      # If you're using your own libft library
│   ├── libft.a                 # Compiled library
│   └── includes/               # Header files for libft
│
└── Makefile                    # Makefile for compiling the project
```

In this structure:

- **src/**: Contains the source code files for the project.
    - **parsing/**: Functions for parsing the configuration file.
        - **color/**: Functions for parsing and validating color settings.
        - **config/**: Functions for parsing and validating configuration settings.
        - **map/**: Functions for parsing and validating map settings.
        - **texture/**: Functions for parsing and validating texture settings.
    - **rendering/**: Functions for rendering the 3D world.
    - **utils/**: Utility functions for common tasks.
- **includes/**: Contains header files for the project.
    - **cub3d.h**: Main header file for the project.
    - **engine.h**: Header file for the graphics rendering engine.
- **assets/**: Directory for storing texture files (.xpm or .png) and map configuration files (.cub).
    - **textures/**: Directory for storing texture files.
    - **maps/**: Directory for storing map configuration files.
- **libft/**: If you're using your own libft library, this directory contains the compiled library and header files.
- **Makefile**: Makefile for compiling the project.

## I. Project Setup

### Step 1: Setup

Create the project directory structure and necessary files.

```bash
mkdir -p cub3d/src/main cub3d/src/parsing cub3d/src/rendering cub3d/src/utils
mkdir -p cub3d/includes cub3d/assets/textures cub3d/assets/maps
```

### Step 2: Create Files

Create the main source files and header file for the project.

```bash
touch cub3d/src/main/main.c
touch cub3d/src/parsing/parse.c
touch cub3d/src/rendering/render.c
touch cub3d/src/utils/utils.c
touch cub3d/includes/cub3d.h
touch cub3d/assets/textures/.gitkeep
touch cub3d/assets/maps/.gitkeep
touch cub3d/Makefile
```

## II. Parsing Configuration File

The first step in our project is to read and parse the configuration file (.cub) that defines our game settings. The configuration file contains information about the map layout, textures, colors, resolution, and other parameters needed to set up the game environment.

Here's an example of a simple configuration file:

```cub
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 0,0,100

 1111111        111111111
110000011      10000000001
100000001     1000000000001
 1000001     100000000000001
  11011      1000000000000001
   101        1000000100000001
   101         100001 100000001
   101111111111100000100000001
   10000000000000000000000001
   1011111111111000000000001
   101         100000000001
   101        100000000001
  11011      100000000001
 1000001     1000000N0001
100000001     10000000001
110000011      1000000001
 1111111        111111111
```

In this example, the configuration file specifies the following settings:

- **Textures**:
    - North wall texture: `./assets/textures/north.png`
    - South wall texture: `./assets/textures/south.png`
    - West wall texture: `./assets/textures/west.png`
    - East wall texture: `./assets/textures/east.png`
- **Floor Color**: RGB value (220,100,0)
- **Ceiling Color**: RGB value (0,0,100)
- **Map Layout**:
    - `1`: Wall
    - `0`: Empty space
    - `N`, `S`, `W`, `E`: Player starting position and direction

Our task is to read and parse this configuration file to extract these settings and use them to set up the game environment.

To achieve this, we'll need to implement functions to:

- Open and read the configuration file.
- Parse the data to extract relevant settings.
- Validate the data to ensure it's in the correct format.
- Store the settings in appropriate data structures for later use.

### Map requirements

1. **Map Elements**: The map must contain only the following elements:
    - 0: Empty space
    - 1: Wall
    - 2: Sprite (bonus)
2. **Map Shape**: The map must be surrounded by walls (1) on all sides. The map's shape can be a rectangle, but it can also have holes inside it.
3. **Valid Characters**: Only the map elements mentioned above and spaces are valid characters in the map. Any other character is considered invalid.
4. Starting Position: The map must have a starting position for the player. This starting position must be represented by one of the following characters:
    - N: North
    - S: South
    - W: West
    - E: East

### Prsing and Storing the Configuration File

To parse the configuration file, we'll need to:

1. **Read the File**: Open and read the configuration file line by line.
2. **Parse the Data**: Extract relevant settings from each line of the file.
3. **Store the Data**: Store the settings in appropriate data structures for later use.

Here's a basic outline of the steps involved in parsing the configuration file:

1. **Open File**: Open the configuration file for reading using the `open` system call.
2. **Read Lines**: Read each line of the file using the `get_next_line` function.
3. **Parse Data**: Parse the data from each line to extract relevant settings (e.g., textures, colors, map layout).

To store the configuration settings, we'll define a `t_config` structure to hold the extracted data:

```c
typedef struct s_config
{
    char    *no_texture;
    char    *we_texture;
    char    *so_texture;
    char    *ea_texture;
    int     floor_color;
    int     ceiling_color;
    char    **map;
    char    **map_copy;
    size_t  map_width;
    size_t  map_height;
    int     map_started;
}    t_config;
```

The `t_config` structure contains fields to store the configuration settings extracted from the configuration file. We'll use this structure to store the textures, colors, and map layout.

```bash
└── src
    ├── parsing
    │   ├── color
    │   │   ├── color_parsing.c
    │   │   └── color_validation.c
    │   ├── config
    │   │   ├── config_file_parsing.c
    │   │   └── config_validation.c
    │   ├── map
    │   │   ├── map_parsing.c
    │   │   └── map_validation.c
    │   └── texture
    │       ├── texture_parsing.c
    │       └── texture_validation.c
```

The `color`, `config`, `map`, and `texture` directories contain functions for parsing and validating the color, configuration, map, and texture settings, respectively. Each directory contains two files: one for parsing the data and one for validating it.

By parsing and storing the configuration file, we'll be able to extract the game settings needed to set up the game environment.

## III. Initialize Graphics

The next step in our project is to initialize the graphics rendering engine using the `minilibx` library. The Minilibx library is a simple graphics library that provides functions for creating windows, drawing pixels, and handling user input.

To set up the graphics rendering engine, we'll need to:

- Initialize the Minilibx library.
- Create a window for rendering the game.
- Set up a buffer for rendering pixels to the window.
- Handle user input for player controls.

Here's a basic outline of the steps involved in setting up the graphics rendering engine:

1. **Initialize Minilibx**: Start by initializing the Minilibx library to set up the graphics environment.
2. **Create Window**: Create a window for rendering the game using the `mlx_new_window` function.
3. **Setup Buffer**: Set up a buffer for rendering pixels to the window using the `mlx_new_image` function.
4. **Handle User Input**: Implement functions to handle user input for player controls (e.g., movement, rotation).

By setting up the graphics rendering engine, we'll be able to display the game world and interact with it using player controls.

## Raycasting Engine

## Texture Mapping

## Player Movement and Controls

## Rendering Game World

## Error Handling and Cleanup

## Bonus Features

## Resources

### Researched Topics

- [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D)
- [Computer Graphics from Scratch](https://www.gabrielgambetta.com/computer-graphics-from-scratch/)

**[Mathematics]**

**Trigonometry:** Essential for dealing with angles and rotations in 3D space. You'll frequently use trigonometric functions like sine, cosine, and tangent to calculate positions and angles.

- [Trigonometry - Easy to understand 3D animation](https://youtu.be/ovLbCvq7FNA)
- [Trigonometry - Khan Academy](https://www.khanacademy.org/math/trigonometry)
- [Trigonometry - Math is Fun](https://www.mathsisfun.com/algebra/trigonometry.html)
- [Trigonometry - Purplemath](https://www.purplemath.com/modules/trig.htm)




- [Online Computer Graphics II](https://www.youtube.com/watch?v=U0-58hpucp4)
- [Binary Space Partitioning](https://www.youtube.com/watch?v=6vrPCkHqWwg)

**[Raycasting]**

- [Raycasting](https://en.wikipedia.org/wiki/Ray_casting)
- [RayCasting Tutorials by Lode Vandevenne](https://harm-smits.github.io/42docs/projects/cub3d) 
- [Matt Godbolt - Wolfenstein 3D's map renderer](https://www.youtube.com/watch?v=eOCQfxRQ2pY) ⭐
- [3DSage - Make Your Own Raycaster - Part 1](https://www.youtube.com/watch?v=gYRrGTC7GtA) 
- [3DSage - Make Your Own Raycaster - Part 2](https://www.youtube.com/watch?v=PC1RaETIx3Y) 
- [3DSage - Make Your Own Raycaster - Part 3](https://www.youtube.com/watch?v=w0Bm4IA-Ii8)
- [Pikuma - Raycasting](https://drive.google.com/drive/folders/1GzCshkJDq5x4EZHRnoir6g4YeQ-9lU_r)
- [Ray-Casting Tutorial by F. Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents)
- [Super Fast Ray Casting in Tiled Worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA)

**[MinilibX]**

- [Introduction to the MinilibX](https://www.youtube.com/watch?v=bYS93r6U0zg)
- [x.org Documentation](https://www.x.org/wiki)
- [libX11 Documentation](https://www.x.org/releases/X11R7.6/doc/libX11/specs/libX11/libX11.html)

**[42 students articles]**

- [Cub3D Tutorial [Using angles]. INTRODUCTION](https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf)
 - [Jun Han Ng - Cub3D ](https://hackmd.io/@nszl/H1LXByIE2#introduction)
