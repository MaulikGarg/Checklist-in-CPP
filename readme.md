# Checklist (To-Do List Manager)

## 📌 Overview
This is a **console-based To-Do List Manager** built in C++ using **CMake** and **C++**. It allows users to create multiple lists, add or remove items from them, and manage them efficiently.

## 🛠 Features (In Progress)
- Create and manage multiple lists.
- Add and remove items from lists.
- Display available lists and their contents.
- Store lists in memory.

## 🏗 Project Structure
```
Checklist/
│── src/
│   ├── bossList.cpp  # Manages multiple lists
│   ├── bossList.h    # BossList class definition
│   ├── list.cpp      # Manages individual list operations
│   ├── list.h        # List class definition
│   ├── getInput.cpp  # Handles user input
│   ├── getInput.h    # Input validation functions
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

## 🏗 How It Works
### **Main Components**
1. **BossList Class** → Manages multiple lists.
2. **List Class** → Handles items within a single list.
3. **getInput Module** → Ensures valid user input.

### **Usage**
- **Add a List** → Enter a name when prompted.
- **Remove a List** → Choose an existing list to delete.
- **Add/Remove Items** → Select a list and modify its contents.
- **View Lists** → Display available lists and their items.

## ✨ Current Goals
- Add basic JSON parsing and saving/loading of BossList.

## 🚀 Future Improvements
- Add lookup to look for an individual element in all lists and show every list containing that.
- Command-line arguments for quick list management
- GUI version

## 📜 License
This project is open-source and free to use.

## 🤝 Contributing
Contributions are welcome! Feel free to submit pull requests or report issues.

