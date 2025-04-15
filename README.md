# 🐾 **DOOG** 🐶  
*A Cat-and-Dog-Themed Doom-Like Shooter*  

---

## **Description**  
**Doog** is a fast-paced FPS where you play as **Doogguy**, a brave canine warrior tasked with defending your backyard from an army of mischievous cats! Use your bark attacks, avoid claw swipes, and navigate a dynamic maze filled with power-ups and surprises. Built with **Raylib** and C++, this game combines OOP principles with chaotic cat-dog warfare.  

---

## **Features**  
### **Gameplay**  
- 🐕 **Play as Doogguy**: A dog with a gun and bone-collecting mechanics.  
- 🐈 **Enemy Cats**: Evil cats that patrol the maze and attack on sight.  
- 🦴 **Power-Ups**: Collect bones to upgrade your bark radius or speed.  
- 🧀 **Dynamic Maze**: Procedurally generated levels with hidden secrets.  

### **Technical Requirements Met**  
- ✅ **OOP Implementation**: Inheritance (`GameObject` → `Player`, `Enemy`), constructors/destructors, virtual methods, operator overloading.  
- ✅ **Dynamic Memory**: Cats spawn dynamically based on difficulty.  
- ✅ **Static/Dynamic Arrays**: Maze walls (static), cat patrol paths (dynamic).  
- ✅ **Default Arguments**: `LoadTexture("cat.png", useDefault=true)`.  

---

## **Installation**  
1. **Clone the repository**:  
   ```bash  
   git clone https://github.com/your-username/Doog.git  
   cd Doog  

### **Controls**
**Key**	Action
**WASD**	Move Duke
**Mouse**	Look around
**Space**	Bark attack (short-range)
**E**	Interact/pick up bones
**Esc**	Pause/Quit

### **Class Structure (OOP Highlights)**
**Class**	Key Features
**Player**	Inherits GameObject, uses const float SPEED, virtual Update().
**Enemy**	Overloaded Patrol() method, static totalCats counter.
**Bone**	Dynamic memory allocation for bone spawns.
**Maze**	Static array for walls, dynamic array for power-ups.
