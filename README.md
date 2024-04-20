# cub3D

## Project Overview

Welcome to our cub3d project! As a team, we'll be diving into the exciting world of raycasting and basic 3D graphics programming. Our main goal is to create a simple 3D maze game from scratch using raycasting techniques.

## Summary

This project is inspired by the world-famous [Wolfenstein 3D game](https://en.wikipedia.org/wiki/Wolfenstein_3D), which was the first FPS ever. It is a remarkable technique to explore, and a great opportunity to create a game with a good design and a nice user interface.

![cool-guys-1992-small](https://github.com/zelhajou/42-cub3D/assets/39954629/e53038ee-d9ed-43fa-8f58-44ee63a5ede3)

Developed by [id Software](https://en.wikipedia.org/wiki/Id_Software) and published by [Apogee Software](https://en.wikipedia.org/wiki/Apogee_Software), Wolfenstein 3D was released in 1992. It was a revolutionary game that popularized the FPS genre and helped establish the PC as a gaming platform.

http://users.atw.hu/wolf3d/


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

## Evaluation Criteria
Our project will be evaluated based on various criteria, including:

- **Correctness**: We need to ensure the game works correctly without bugs or crashes.
- **Code Quality**: Let's aim for well-structured, readable, and well-documented code.
- **Performance**: The game should run smoothly without significant lag or performance issues.
- **Bonus Features**: Extra points may be awarded for implementing additional features or going beyond the basic requirements of the project.

## Team Development Steps

As a team, we'll be tackling the cub3d project in a systematic manner to ensure a successful outcome. Here's our proposed development roadmap:

### 1. Project Setup
Set up the project repository, establish communication channels, and assign roles.
- [x] **Create Repository**: Set up a Git repository for the project.
- [ ] **Establish Communication**: Choose communication tools (Discord) and set up regular meeting times.
- [ ] **Assign Roles**: Define roles and responsibilities for each team member.

### 2. Parsing Configuration File
Implement the code to read and parse the configuration file (.cub) to extract game settings.
- [ ] **Read File**: Open and read the .cub configuration file.
- [ ] **Validate Data**: Check for valid map settings, resolution, textures, etc.
- [ ] **Parse Data**: Extract and store relevant information from the configuration file.

### 3. Initialize Graphics
Set up the graphics rendering engine using the `minilibx` library.
- [ ] **Initialize Minilibx**: Set up the Minilibx library for graphics rendering.
- [ ] **Create Window**: Create a window for rendering the game.
- [ ] **Setup Buffer**: Set up a buffer for rendering pixels to the window.

### 4. Raycasting Engine
Develop the raycasting engine to render a 3D perspective view of the game world.
- [ ] **Initialize Ray**: Start with the player's position and direction.
- [ ] **Cast Rays**: Cast rays from the player's position to calculate distances to walls.
- [ ] **Calculate Wall Strips**: Determine the height and texture of each wall strip to draw.

### 5. Texture Mapping
Apply textures to walls to enhance the visual appearance of the game.
- [ ] **Load Textures**: Load wall and sprite textures from files.
- [ ] **Implement Texture Mapping**: Apply textures to the rendered walls.

### 6. Player Movement and Controls
Implement controls to allow the player to move and navigate within the 3D world.
- [ ] **Handle Input**: Implement controls for player movement (e.g., WASD for movement, arrow keys for rotation).
- [ ] **Update Player Position**: Update the player's position based on input and collision detection.


### 7. Rendering Game World
Render the game world using the raycasting results and textures.
- [ ] **Draw Walls**: Render the walls of the 3D world using the raycasting results.
- [ ] **Draw Floor and Ceiling**: Render the floor and ceiling of the 3D world.
- [ ] **Draw Sprites**: Implement sprite rendering if necessary.

### 8. Error Handling and Cleanup
Implement error handling to prevent crashes and ensure a smooth user experience.
- [ ] **Error Checks**: Implement error handling to catch and handle any runtime errors.
- [ ] **Memory Cleanup**: Free allocated memory and resources.
- [ ] **Close Window**: Properly close the graphics window when exiting the game.

### 9. Optimization and Refactoring
Optimize the code for performance and refactor as needed for better readability.
- [ ] **Optimize Raycasting**: Improve raycasting performance if necessary.
- [ ] **Refactor Code**: Clean up and organize the code for better readability and maintainability.

### 10. Bonus Features (Optional)
Implement additional features to enhance the game experience and earn extra points.
- [ ] **Add Features**: Implement additional features like a minimap, HUD, or more complex game mechanics.
- [ ] **Testing**: Thoroughly test the game to ensure all features work as expected.

## Resources

- [RayCasting Tutorials by Lode Vandevenne](https://harm-smits.github.io/42docs/projects/cub3d) [Website]
- [Raycasting in 2D by 3DSage](https://reactive.so/post/42-a-comprehensive-guide-to-cub3d)
- [Cub3D Tutorial [Using angles]. INTRODUCTION](https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf)
- [Computer Graphics from Scratch](https://www.gabrielgambetta.com/computer-graphics-from-scratch/) [Book]
- [Ray-Casting Tutorial by F. Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents) [Website]
- [x.org Documentation](https://www.x.org/wiki) [Website]
- [libX11 Documentation](https://www.x.org/releases/X11R7.6/doc/libX11/specs/libX11/libX11.html)

### Video resources

- [Pikuma - Raycasting](https://drive.google.com/drive/folders/1GzCshkJDq5x4EZHRnoir6g4YeQ-9lU_r)
- [Online Computer Graphics II](https://www.youtube.com/watch?v=U0-58hpucp4)
- [Binary Space Partitioning](https://www.youtube.com/watch?v=6vrPCkHqWwg)
- [Super Fast Ray Casting in Tiled Worlds using DDA](https://www.youtube.com/watch?v=NbSee-XM7WA)
- [Make Your Own Raycaster - Part 1](https://www.youtube.com/watch?v=gYRrGTC7GtA)
- [Make Your Own Raycaster - Part 2](https://www.youtube.com/watch?v=PC1RaETIx3Y) 
- [Make Your Own Raycaster - Part 3](https://www.youtube.com/watch?v=w0Bm4IA-Ii8)
- [Introduction to the MinilibX](https://www.youtube.com/watch?v=bYS93r6U0zg)
