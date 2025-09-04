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

## Usage
### Compile
```bash
g++ -std=c++17 src/lru_cache.cpp -o lru_cache
./lru_cache
```
## Example Run
```bash
Enter cache capacity: 2
Enter commands (PUT key value / GET key / EXIT):
PUT 1 100
Inserted (1, 100)
PUT 2 200
Inserted (2, 200)
GET 1
Value: 100
PUT 3 300
Inserted (3, 300)
GET 2
Key not found
EXIT
Exiting...
```
## Project Structure
```bash
LRU-Cache/
│── src/
│   └── lru_cache.cpp   # Implementation + CLI
│── README.md           # Documentation
```
## License
- This project is open-source under the MIT License.









