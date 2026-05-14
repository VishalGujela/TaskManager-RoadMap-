# TaskManager CLI
Project URL
https://roadmap.sh/projects/task-tracker

A simple command-line task tracker written in C++.

This project allows you to:

* Add tasks
* Update tasks
* Delete tasks
* Mark tasks as done
* Mark tasks as in-progress
* List all tasks
* Filter tasks by status
* Persist tasks using JSON storage

The project uses the following:

* Modern C++
* STL `map`
* `nlohmann/json` for JSON serialization

---

# Features

## Add Tasks

```bash
./task-cli add "Buy groceries"
```

Example Output:

```text
Task added successfully (ID: 0)
```

---

## Update Tasks

```bash
./task-cli update 0 "Buy groceries and cook dinner"
```

---

## Delete Tasks

```bash
./task-cli delete 0
```

---

## Mark Task In Progress

```bash
./task-cli mark-in-progress 0
```

---

## Mark Task Done

```bash
./task-cli mark-done 0
```

---

## List All Tasks

```bash
./task-cli list
```

---

## List Tasks By Status

### Done Tasks

```bash
./task-cli list done
```

### Todo Tasks

```bash
./task-cli list todo
```

### In Progress Tasks

```bash
./task-cli list in-progress
```

---

# Project Structure

```text
TaskTracker/
├── main.cpp
├── cli.hpp
├── task.hpp
├── taskManager.hpp
├── tasks.json
├── README.md
└── .gitignore
```

---

# Build Instructions

## Prerequisites

Install:

* g++
* C++17 support
* nlohmann-json

Ubuntu/Debian:

```bash
sudo apt install g++ nlohmann-json3-dev
```

---

## Compile

```bash
g++ main.cpp -std=c++17 -o task-cli
```

---

# JSON Storage

Tasks are stored in:

```text
tasks.json
```

Example:

```json
[
    {
        "id": 0,
        "description": "Learn C++",
        "status": "to-do",
        "createdAt": "2026-05-14 12:00:00",
        "updatedAt": ""
    }
]
```

---

# Internal Design

## Task Object

Each task contains:

* ID
* Description
* Status
* Created Timestamp
* Updated Timestamp

---

## Task States

Supported states:

* `to-do`
* `in-progress`
* `done`

---

# Example Workflow

```bash
./task-cli add "Learn JSON"
./task-cli add "Practice DSA"

./task-cli mark-in-progress 0
./task-cli mark-done 0

./task-cli list done
```

---

# Future Improvements

Possible enhancements:

* Colored CLI output
* Priority support
* Due dates
* Search tasks
* Sort tasks
* Unit tests
* SQLite storage
* Tags and categories
* Interactive shell mode

---

# Author

Created by Vishal Gujela.
For Fun!!!
Project URL:

[https://github.com/VishalGujela/TaskManager-RoadMap-](https://github.com/VishalGujela/TaskManager-RoadMap-)
