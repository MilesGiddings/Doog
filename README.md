# Neverdog

**A Doom‐style FPS built in C++ and Raylib**  
Object-Oriented Programming in C++ Final Project by Miles Giddings

---

## Project Overview

Neverdog puts you in the paws of Doogguy, a brave dog defending his backyard maze from waves of rogue cats. Along the way you’ll collect bones, avoid traps, and test your reflexes against AI patrols—all built to demonstrate core C++ and OOP concepts.

---

## What’s Included

- **First-person movement** (WASD + mouse look)  
- **Bark “weapon”** with short-range effect  
- **Enemy AI** that patrols and chases on sight  
- **Collectible power-ups** (bones) to boost speed or bark radius  
- **Procedurally assembled maze** using a mix of static arrays and simple random seeding  
- **Collision detection** between player, walls, and enemies*  

---

## C++ / OOP Highlights

- **Inheritance & Polymorphism**  
  - `GameObject` base class with `virtual Update()` and `virtual Draw()`  
  - `Player`, `Enemy`, and `Wall` derived from `GameObject`  

- **Constructors & Destructors**  
  - Initializer lists for const/ID members  
  - Destructors unload Raylib textures (RAII style)  

- **Static & Const Members**  
  - `static int Enemy::totalEnemies` tracks how many cats are live  
  - `const int GameObject::id` gives each object a fixed identifier  

- **Operator Overloading**  
  - `Vector2 operator+(const Vector2&, const Vector2&)` for clean movement math  

- **Aggregation (has-a relationships)**  
  - `Level` class holds arrays/vectors of `Wall` and `Enemy` objects  

- **Free Function with Default Argument**  
  - `Texture2D LoadGameTexture(const std::string& path, bool useDefault = true)`  

- **Memory Management**  
  - Manual `new[]` / `delete[]` for enemy arrays  
  - `std::vector` for projectiles and other dynamic lists  
