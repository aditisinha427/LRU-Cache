# LRU-Cache Implementation (C++)

## Overview
An **O(1) LRU (Least Recently Used) Cache** implementation in C++ using 
`unordered_map` and a doubly linked list.  
Supports efficient `GET` and `PUT` operations with an eviction policy 
for handling fixed capacity.  
Includes a **CLI interface** for real-time interaction.

## Features
- O(1) `GET` and `PUT` operations
- Eviction policy: removes the least recently used element when capacity is full
- Interactive CLI with commands:
  - `PUT <key> <value>` → insert/update a value
  - `GET <key>` → retrieve a value
  - `EXIT` → quit program

## Tech Stack
- Language: **C++17/20**
- STL: `unordered_map`, pointers
- Paradigm: Object-Oriented Programming (OOP)

## 🚀 Usage
### Compile
```bash
g++ -std=c++17 src/lru_cache.cpp -o lru_cache
