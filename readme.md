# Checklist Organizer

## 📌 Overview
This is a **console-based Multi List Manager** built in C++ using **CMake** and **C++**. It allows users to create multiple lists, add or remove items from them, manage them efficiently, and save/load lists using **JSON**.

## 🛠 Features
- Create and manage multiple lists.
- Add and remove items from lists.
- Display available lists and their contents.
- Store lists in memory.
- Save and load lists using JSON.

## 🏗 Project Structure
```
Checklist/
│── lib/
│   ├── json.hpp       # API for handling JSON
│── src/
│   ├── bossList.cpp  # Manages multiple lists
│   ├── bossList.h    # BossList class definition
│   ├── list.cpp      # Manages individual list operations
│   ├── list.h        # List class definition
│   ├── getInput.cpp  # Handles user input
│   ├── getInput.h    # Input validation functions
│   ├── fileIO.cpp    # Handles file operations (JSON read/write)
│   ├── fileIO.h      # File I/O functions
│   ├── main.cpp      # Entry point of the program
│── CMakeLists.txt    # CMake build configuration
│── README.md         # Project documentation
```

## 🏗 Setup & Build
### **1. Clone the Repository**
```sh
git clone https://github.com/MaulikGarg/Checklist-in-CPP.git
cd Checklist-in-CPP
```

### **2. Build the Project**
```sh
mkdir Build && cd Build
cmake ..
cmake --build .
```

### **3. Run the Program**
```sh
./list  # On Linux/macOS
list.exe  # On Windows
```

### **Important Note**
The .json lists are saved in a **/lists** folder. Please note that it must be in the same directory as the executable. If there is no **/lists** folder, the project will create one.

## 🏗 How It Works
### **Main Components**
1. **BossList Class** → Manages multiple lists.
2. **List Class** → Handles items within a single list.
3. **getInput Module** → Ensures valid user input.
4. **fileIO Module** → Handles JSON save/load operations.

### **Usage**
- **Add a List** → Enter a name when prompted.
- **Remove a List** → Choose an existing list to delete.
- **Add/Remove Items** → Select a list and modify its contents.
- **View Lists** → Display available lists and their items.
- **Search Items** → Lookup an item across all lists.
- **Save & Load** → Data persists between sessions using JSON.

## ✨ Current Goals
- Search for an item across all lists.
- Improve JSON parsing for better error handling.
- Enhance file handling performance.

## 🚀 Future Improvements
- Add a search feature to find an element in all lists.
- Implement command-line arguments for quick list management.
- Develop a GUI version.

## 📜 License
This project is open-source and free to use.

## 🤝 Contributing
Contributions are welcome! Feel free to submit pull requests or report issues.

