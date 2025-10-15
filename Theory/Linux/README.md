*Embedded Firmware Course* — including:

* Why Linux
* Why WSL Ubuntu
* Linux basics
* GCC setup
* Hello World compilation
* Assignments & summary

This version is **ready for GitHub**, **slides**, or **video recording script** — smooth, clean, and flow-based for 2 hours.

---

````markdown
# 🧠 Introduction to Linux Environment for Embedded Firmware Development  
**Duration:** 2 Hours  
**Platform:** WSL (Ubuntu on Windows)

---

## 🎯 Learning Objectives
By the end of this session, you will:
- Understand **why Linux is used in Embedded Systems**
- Learn **why WSL (Ubuntu)** is the best environment for students
- Explore the **Linux file system and navigation commands**
- Set up **GCC compiler** and understand its workflow
- Write, compile, and run a simple **C program**
- Understand how compilation works (Preprocessing → Linking)
- Practice assignments from **easy → hard**

---

## 🧩 1. Why Linux for Embedded Programming?

### 💡 1. Industry Standard
- Most embedded devices (IoT, routers, automotive ECUs, smart TVs, drones) run **Linux or Linux-based OS**.
- Firmware engineers work in Linux because it gives full system control and open-source tools.

---

### 🧰 2. Open Source & Developer Friendly
- Linux is **free and open-source** — no license required.
- Developers can modify, rebuild, or debug kernel-level code if needed.

---

### ⚙️ 3. Command-Line Power
- The Linux terminal is your **main development tool**.
- Common commands used in embedded projects:
  - `gcc` → compile code  
  - `make` → automate builds  
  - `gdb` → debugging  
  - `grep`, `awk`, `sed` → log and text filtering  
  - `lsusb`, `dmesg` → device and hardware info  

---

### 🧩 4. Cross-Compilation Support
- In embedded systems, code runs on ARM-based boards but is compiled on a PC.
- Linux supports **cross-compilers** like `arm-none-eabi-gcc`.

---

### 🧠 5. Automation Friendly
- Linux scripting makes repetitive tasks (building, flashing, logging) easy using **bash** or **Python scripts**.

---

### 🔍 6. Hardware-Level Debugging
- Direct access to `/dev/ttyUSB0`, GPIOs, and serial devices.
- Ideal for flashing firmware and debugging MCU boards.

---

### 🌎 7. Real Engineering Ecosystem
- 90% of embedded toolchains (ST, TI, NXP, Microchip, etc.) work smoothly on Linux.
- Open-source communities also share scripts and drivers for Linux.

---

## 🧱 2. Why WSL (Ubuntu on Windows)?

### 🧩 1. Best of Both Worlds
- Use **Windows and Linux together** — no dual boot needed.
- Develop in Linux tools while using Windows for documents, IDEs, etc.

---

### ⚡ 2. Lightweight and Fast
- WSL2 uses a **real Linux kernel** running inside Windows.
- Commands run nearly as fast as native Linux.

---

### 🖥️ 3. Works Directly Inside Windows
You can switch easily:
```bash
C:\Users\Boss\project> wsl
$ gcc main.c -o main
$ ./main
````

---

### 🔧 4. All Embedded Tools Supported

* `gcc`, `make`, `gdb`, `git`, `python3` — all work perfectly.
* No need for a full Ubuntu installation.

---

### 🔄 5. File Sharing Between Windows & Linux

* Files are accessible both ways.
* Edit in VS Code (Windows) → Compile inside WSL.

---

### 🧰 6. Simple for Beginners

```bash
wsl --install
```

That’s all you need to set up Ubuntu Linux inside Windows.

---

### 🚀 7. Real Industry Workflow

* Many professionals use **VS Code + WSL + GCC + Git** setup.
* This is exactly what you’ll learn in this course.

---

## 🧭 3. Navigating Linux File System

### Common Commands

| Command          | Description            |
| ---------------- | ---------------------- |
| `pwd`            | Show current directory |
| `ls`             | List files/folders     |
| `cd <folder>`    | Move into folder       |
| `mkdir <folder>` | Create a folder        |
| `rmdir <folder>` | Remove a folder        |
| `rm <file>`      | Remove a file          |
| `clear`          | Clear terminal screen  |

### Example:

```bash
pwd
/home/student
ls
mkdir test
cd test
```

---

## ⚙️ 4. Setting Up GCC Compiler

### What is GCC?

**GCC (GNU Compiler Collection)** converts your C code into machine-executable format.

### Install GCC 

```bash
wsl          //it opens wsl from cmd prompt
sudo apt update
sudo apt install gcc
```

### Check Version

```bash
gcc --version
```

✅ Output should show GCC version details.

---

## 💻 5. Creating, Compiling & Running a C Program

### Step 1: Create a new file

```bash
nano hello.c
```

### Step 2: Type this C code

```c
#include <stdio.h>

int main() {
    printf("Hello, Embedded Linux!\n");
    return 0;
}
```

### Step 3: Save and Exit Nano

* **Ctrl + O** → Save
* **Enter** → Confirm file name
* **Ctrl + X** → Exit editor

---

### Step 4: Compile the program

```bash
gcc hello.c -o hello
```

### Step 5: Run the program

In WSL, the compiled output is a Windows-compatible `.exe` file.

Run it as:

```bash
./hello.exe
```

or simply:

```bash
hello.exe
```

✅ **Output:**

```
Hello, Embedded Linux!
```

---

## 🔍 6. Understanding Compilation Steps

| Step          | Command                     | Description                            |
| ------------- | --------------------------- | -------------------------------------- |
| Preprocessing | `gcc -E hello.c -o hello.i` | Expands macros, includes headers       |
| Compilation   | `gcc -S hello.i -o hello.s` | Converts to assembly                   |
| Assembly      | `gcc -c hello.s -o hello.o` | Converts to object code                |
| Linking       | `gcc hello.o -o hello.exe`  | Combines everything into final program |

> 💬 Linking step creates the final `.exe` — the complete program ready to run.

---

## 🎥 7. Suggested Video Plan (for 5–10 mins each)

| Topic                           | Duration | Type          |
| ------------------------------- | -------- | ------------- |
| Why Linux & Why WSL             | 10 min   | Slides        |
| WSL Setup                       | 10 min   | Demo          |
| File System Navigation          | 10 min   | Demo          |
| GCC Installation                | 5 min    | Demo          |
| Writing & Compiling Hello World | 10 min   | Demo          |
| Compilation Process Explained   | 5 min    | Slides + Demo |
| Assignments & Wrap-Up           | 10 min   | Slides        |

---

## 🧠 8. Assignments (Easy → Hard)

| Level     | Task                                 | Hint                        |
| --------- | ------------------------------------ | --------------------------- |
| 🟢 Easy   | Print your name using `printf()`     | Simple print statement      |
| 🟡 Medium | Take two numbers and print their sum | Use `scanf()` for input     |

---

## 🧩 9. Example Output in WSL

```bash
C:\Users\Akshay\test>nano hello.c

C:\Users\Akshay\test>gcc hello.c -o hello

C:\Users\Akshay\test>hello.exe
Hello, Embedded Linux!
```

---

## 🧾 10. Recap

✅ You learned:

* Why **Linux** is essential for embedded firmware
* Why **WSL Ubuntu** is the best setup for beginners
* How to navigate the Linux terminal
* How to install and use **GCC**
* How the **C compilation process** works
* How to write, compile, and execute your own programs

---

💬 *"Before you blink an LED on STM32, you should know how to compile code in Linux — that’s where every embedded journey begins!"*

```

