
---

````markdown
# 🧠 Introduction to Linux Environment (2 Hours)

## 🎯 Objective
By the end of this session, students will:
- Understand and navigate the Linux file system  
- Set up and use **GCC (GNU Compiler Collection)**  
- Create, compile, and run C programs using **WSL (Windows Subsystem for Linux)**  
- Get comfortable with the terminal workflow for embedded firmware development  

---

## 🕒 Duration Breakdown

| Topic | Duration |
|-------|-----------|
| Linux-based Virtual Machine Setup (WSL) | 20 mins |
| File System & Navigation | 20 mins |
| Understanding & Setting up GCC | 20 mins |
| Creating, Compiling & Running a C Program | 40 mins |
| Assignments | 20 mins |

---

## 🧩 1. Linux Based Virtual Machine Setup (WSL)

### ✅ What is WSL?
WSL (Windows Subsystem for Linux) lets you run Linux commands on Windows — no dual boot needed.

### 🪜 Steps to Install WSL
1. Open **PowerShell as Administrator**
2. Run this command:
   ```bash
   wsl --install
````

3. Restart your system when prompted.
4. Open the **Ubuntu** app from the Start menu.
5. Create a username and password for your Linux environment.

---

## 🧭 2. File System and Navigation

| Command            | Description                     |
| ------------------ | ------------------------------- |
| `pwd`              | Print current working directory |
| `ls`               | List files and directories      |
| `cd <directory>`   | Change directory                |
| `mkdir <dir_name>` | Create a new directory          |
| `rmdir <dir_name>` | Remove an empty directory       |
| `rm <file_name>`   | Remove a file                   |
| `clear`            | Clear the terminal              |

### 💡 Example

```bash
pwd
/home/akshay
ls
mkdir test
cd test
```

---

## ⚙️ 3. Understanding and Setting up GCC

GCC (GNU Compiler Collection) is the compiler we use to compile C programs.

### 🪄 To install GCC (if not installed):

```bash
sudo apt update
sudo apt install gcc
```

### ✅ Verify installation:

```bash
gcc --version
```

---

## 💻 4. Creating a C File and Compilation

### Step 1: Create and edit a file

```bash
nano hello.c
```

### Step 2: Write your first C program

```c
#include <stdio.h>

int main() {
    printf("Hello, Embedded Linux!\n");
    return 0;
}
```

### Step 3: Save and Exit Nano

* Press **Ctrl + O** → Save
* Press **Enter** → Confirm file name
* Press **Ctrl + X** → Exit

### Step 4: Compile the program

```bash
gcc hello.c -o hello
```

### Step 5: Run the program

👉 Since you’re using **WSL**, it creates a Windows-compatible `.exe` file.
You can run it in two ways:

```bash
./hello.exe
```

or simply:

```bash
hello.exe
```

---

### ⚙️ Compilation Steps (Behind the Scenes)

| Stage         | Command                     | Description                                    |
| ------------- | --------------------------- | ---------------------------------------------- |
| Preprocessing | `gcc -E hello.c -o hello.i` | Expands macros and includes header files       |
| Compilation   | `gcc -S hello.i -o hello.s` | Converts C code to assembly                    |
| Assembly      | `gcc -c hello.s -o hello.o` | Converts assembly to machine code              |
| Linking       | `gcc hello.o -o hello.exe`  | Combines all objects into the final executable |

> 💬 **Comment:** The linking step generates the final executable — `hello.exe` in WSL.

---

## 🎥 5. Video Plan (5–10 min per topic)

Each video should contain:

* 1–2 PPT slides explaining the concept
* Live terminal demo
* Simple example per concept

| Topic                              | Duration | Type          |
| ---------------------------------- | -------- | ------------- |
| WSL Setup                          | 10 min   | Demo          |
| File System Navigation             | 5 min    | Demo          |
| GCC Setup                          | 5 min    | Demo          |
| Writing and Compiling Hello World  | 10 min   | Demo          |
| Explanation of Compilation Process | 5 min    | Slides + Demo |

---

## 🧠 6. Assignments (Easy → Hard)

| Level     | Task                                                                    | Hint                     |
| --------- | ----------------------------------------------------------------------- | ------------------------ |
| 🟢 Easy   | Create and run a C program that prints your name.                       | Modify `printf()`        |
| 🟡 Medium | Write a program that takes two numbers as input and prints their sum.   | Use `scanf()`            |
| 🔴 Hard   | Create a program that reads a text file and counts the number of lines. | Use `fopen()`, `fgets()` |

---

## 🧩 7. Expected Output

```bash
C:\Users\Akshay\test>nano hello.c

C:\Users\Akshay\test>gcc hello.c -o hello

C:\Users\Akshay\test>hello.exe
Hello, Embedded Linux!
```

---

## 🧾 Summary

✅ You learned how to:

* Use **WSL as a Linux workspace**
* Navigate the file system
* Install and use **GCC**
* Create, compile, and run **C programs**
* Understand **GCC’s 4-step compilation process**

---

## 📸 Optional: Screenshot Placeholders

Add your screenshots to make it visual for students:

```
![WSL Setup](images/wsl_setup.png)
![File Navigation](images/file_navigation.png)
![GCC Installation](images/gcc_install.png)
![Compilation Demo](images/compile_run.png)
```

---



```

---

```
