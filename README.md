# MonsArena ⚔️

MonsArena is a console-based 2-player monster battle game built in C++ using Object-Oriented Programming principles.

Players choose elemental monsters and battle each other using:
- Normal attacks
- Healing abilities
- Powerful special moves

The game includes elemental strengths & weaknesses, health bars, special charge mechanics, and funny battle commentary for an engaging gameplay experience.

---

# 🎮 Features

## ⚔️ Turn-Based Combat
- Two-player battle system
- Alternate turns
- Strategic gameplay

## 🌟 Elemental Power System
Choose from 4 monster elements:
- Fire 🔥
- Water 🌊
- Air 🌪️
- Earth 🌍

Each element has strengths and weaknesses against others.

---

# 🧠 Element Advantages

| Element | Strong Against | Weak Against |
|----------|----------------|---------------|
| Fire  | Air  | Water  |
| Water  | Fire  | Earth  |
| Air  | Earth  | Fire  |
| Earth  | Water  | Air  |

Damage multipliers:
- Advantage → `1.5x damage`
- Disadvantage → `0.5x damage`

---

# ✨ Special Move System

- Players charge a special bar during battle
- Special moves become available when the bar is full
- Special attacks deal massive damage

---

# ❤️ Health & Battle UI

The game includes:
- Health bars
- Special bars
- Battle commentary
- Win/Lose messages
- Random death quotes

Example:

```text
Dragon (Fire) HP: [##############------] 70/100
Special Bar: [**-] 2/3
```

---

# 🛠️ Concepts Used

## Object-Oriented Programming (OOP)
Implemented using:
- Classes
- Inheritance
- Polymorphism
- Encapsulation
- Virtual Functions

---

# 📂 Project Structure

```bash
MonsArena/
│
├── monster.cpp
└── README.md
```

# 🎯 Gameplay Flow

1. Player 1 enters monster name and selects element
2. Player 2 enters monster name and selects element
3. Players take turns choosing actions:
   - Attack
   - Heal
   - Special Move
4. Battle continues until one monster is defeated

---

# 🕹️ Available Actions

| Action | Description |
|--------|-------------|
| Attack | Deals elemental damage |
| Heal | Restores 20 HP |
| Special Move | High damage attack after charging |

---

# 📸 Example Battle

```text
>>> Blaze's Turn <<<

1. Attack
2. Heal (+20 HP)
3. Special Move

Enter action:
```
---

# 📈 Learning Objectives

This project demonstrates:
- OOP Design
- Turn-based game logic
- Enums in C++
- Randomization
- Dynamic memory allocation
- Console UI design
- Game state management

---

# 🚀 Future Improvements

Possible upgrades:
- Single-player mode vs AI
- More monster classes
- Additional elemental types
- Critical hits
- Status effects
- Save/load game system
- Multiplayer networking
- GUI version using SFML or SDL

---

# 👨‍💻 Author

Developed as a C++ OOP Game Project.

---
