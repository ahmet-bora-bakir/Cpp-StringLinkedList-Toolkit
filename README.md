# Cpp-StringLinkedList-Toolkit
---

```markdown
# C++ Custom String Linked List Implementation

A robust, memory-efficient **Singly Linked List** library developed from scratch in C++. This project serves as a comprehensive demonstration of manual memory management, pointer manipulation, and fundamental data structure algorithms.

## ✨ Key Features

This implementation provides a feature-rich toolkit for managing a linked list of strings:

* **Core Functionality:** Standard operations including `push_back`, `push_front`, `insert_at`, `erase_at`, and `clear`.
* **Advanced Algorithms:**
    * `findMiddleNode()`: Locates the middle element using the **Tortoise and Hare** (Slow/Fast Pointer) strategy.
    * `getSmallestNode()`: Efficiently identifies the lexicographically smallest string.
    * `moveSmallestToFront()`: Sophisticated node re-linking to move the minimum element to the head without data copying.
* **Memory Management:** Strictly adheres to the **Rule of Three** (Destructor, Copy Constructor, and Assignment Operator) to ensure deep copying and prevent memory leaks.
* **Interactive CLI:** A user-friendly, menu-driven terminal interface for real-time interaction.
* **Error Handling:** Robust validation with `try-catch` blocks for out-of-bounds access.

## 🛠️ Technical Specifications

* **Language:** C++11 or higher
* **Memory Model:** Manual dynamic allocation (`new` / `delete`)
* **Design Principle:** RAII (Resource Acquisition Is Initialization)

## 🚀 Getting Started

### Prerequisites
A C++ compiler like **GCC (g++)**, **Clang**, or the one built into **Xcode/MSVC**.

### Installation & Execution

1. **Clone the repository:**
```bash
git clone [https://github.com/](https://github.com/)[ahmet-bora-bakir]/[Cpp-StringLinkedList-Toolkit].git

```

2. **Navigate to the project directory:**

```bash
cd [Cpp-StringLinkedList-Toolkit]

```

3. **Compile the source files:**

```bash
g++ main.cpp LinkedList_string.cpp -o LinkedListApp

```

4. **Run the application:**

```bash
./LinkedListApp

```

## 📂 File Structure

* `Node.h`: Header for the `Node` class with `operator<<` visualization.
* `LinkedList_string.h`: Interface for the `LinkedList` class.
* `LinkedList_string.cpp`: Implementation of the linked list logic.
* `main.cpp`: Driver program with an interactive test menu.

## 📊 Example Usage

```text
Menu:
1. Add an element
7. Print the linked list
13. Move smallest to front

Selection: 1 -> "Cherry"
Selection: 1 -> "Apple"
Selection: 1 -> "Banana"
Selection: 7 -> Apple -> Cherry -> Banana -> 

```

---

Developed as a deep dive into C++ Memory Management and Data Structures.

```
