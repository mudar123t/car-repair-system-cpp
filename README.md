# Car Repair Management System (C++)

A C++ console-based car repair system that manages customer and vehicle information using file handling and object-oriented programming. Built as a final project for a programming course.

## Project Context
- Final semester C++ project
- Focus on file handling, class structures, and system simulation

## Features
- Add/edit/delete customer records
- Add/edit/delete vehicle records
- Simulate car repair system logic
- File persistence via `.txt` files
- Simple console-based UI

## Files & Structure
  main.cpp: Entry point
  
  car.cpp / car.h: Car-related data and operations
  
  customer.cpp / customer.h: Customer data logic
  
  car_repair_library.*: Common repair logic
  
  cars.txt, customers.txt: Persistent storage
  
  car_repair_system.exe: Compiled executable


  ## How to Compile
Using g++:
  bash
  g++ main.cpp car.cpp customer.cpp car_repair_library.cpp -o car_repair_system

  ./car_repair_system


## Notes:
  This is a course project built for learning purposes.
  
  Tested on Windows with standard console.


