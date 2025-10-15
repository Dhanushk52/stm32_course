
---

# 🎙️ **2-Hour Voice-Over Script: Introduction to Linux Environment for Embedded Firmware Development**

---

## 🕐 Total Duration: ~2 Hours

### Structure:

* 1st Hour → *Theory + Why Linux + Why WSL + Commands*
* 2nd Hour → *Practical Demo + GCC Setup + Hello World + Assignments*

---

## 🎬 **INTRO (For Beginners) — 0:00 to 5:00**

> (Speak slowly and friendly)

"Hey everyone, welcome to this session — this is our very first step into the **Linux environment for embedded firmware development**.

Before we start working with microcontrollers, STM32 boards, and firmware tools, we must first understand where all the development happens — and that’s inside **Linux**.

Now, don’t worry if you’ve never used Linux before.
In this session, we’ll go very slow, starting from what Linux actually is, why we use it for embedded, and how we can install and use **Linux inside Windows** using **WSL**, also called the *Windows Subsystem for Linux*.

We’ll also learn how to navigate inside Linux, install the **GCC compiler**, and finally write and run our first **Hello World** program — just like embedded engineers do in the real world.

So, let’s get started."

---

## 🧠 **1. Why Linux for Embedded Programming — 5:00 to 25:00**

"First, let’s answer the big question — why Linux?

If you see today’s embedded systems — whether it’s an IoT device, a router, a car ECU, a smart TV, or even a drone — most of them are either built on **Linux** or developed using Linux tools.

That’s why Linux is the **industry standard** for firmware and embedded engineers.

Now let’s break down the reasons."

---

### 💡 1. Industry Standard

"Almost every embedded company — STMicroelectronics, Texas Instruments, NXP, Microchip, all use Linux for building and debugging firmware.
It’s not because Linux looks cool — it’s because Linux gives full control of the system.

When you write firmware, you’re working close to the hardware.
Linux gives you that low-level access — things like serial ports, GPIO, USB devices — all can be easily accessed through Linux commands."

---

### 🧰 2. Open Source & Developer Friendly

"Linux is **free and open-source**.
You don’t have to buy any license like Windows or macOS.
You can modify anything, experiment, and even explore the kernel itself.

That’s why engineers love it — it gives you full freedom."

---

### ⚙️ 3. Command Line Power

"In embedded development, we don’t click buttons — we type commands.

The Linux **terminal** is our main workspace.
For example:

* `gcc` is used to compile C programs
* `make` is used to automate builds
* `gdb` for debugging
* `grep`, `awk`, `sed` for searching through logs
* `lsusb` and `dmesg` to check connected devices

Once you learn these commands, you can do anything — faster and smarter."

---

### 🧩 4. Cross Compilation

"When we compile firmware for STM32 or Raspberry Pi, our code runs on an ARM processor, not on our laptop’s CPU.
So, we use a special compiler called a **cross-compiler**, like `arm-none-eabi-gcc`.
Linux supports these toolchains easily — that’s another reason why we prefer Linux."

---

### 🧠 5. Automation Friendly

"In embedded, we repeat a lot of tasks — compiling, flashing, logging.
Linux allows us to automate everything using simple **bash scripts** or Python.
This is how real firmware teams build systems automatically every day."

---

### 🔍 6. Hardware-Level Debugging

"Linux gives direct access to hardware ports like `/dev/ttyUSB0`.
That’s your serial port — and we use that to flash or debug MCUs.
So without Linux, debugging firmware is often painful."

---

### 🌎 7. Real Engineering Ecosystem

"Finally, most open-source tools and drivers — even those shared by embedded communities — are designed for Linux first.
So, learning Linux is not optional anymore; it’s essential."

---

## 💻 **2. Why WSL (Ubuntu on Windows) — 25:00 to 45:00**

"Now, many of you might be thinking — *‘I have Windows on my laptop, do I need to install Linux separately?’*

The answer is **No.**

You can use **WSL — Windows Subsystem for Linux** — which lets you run Ubuntu Linux *inside* Windows, without dual booting."

---

### 🧩 1. Best of Both Worlds

"With WSL, you can use your Windows software like VS Code, STM32CubeIDE, or browsers, and still run Linux commands inside the same system.
It’s like having both environments side by side."

---

### ⚡ 2. Lightweight and Fast

"WSL2 runs a real Linux kernel inside Windows.
It’s super fast, doesn’t need a separate partition, and boots in seconds."

---

### 🖥️ 3. Switch Easily Between Windows & Linux

"Let me show you how it looks:

```bash
C:\Users\Boss\project> wsl
$ gcc main.c -o main
$ ./main
```

You just type `wsl` in your Windows terminal — and instantly, you’re inside Ubuntu.
Now you can use Linux commands."

---

### 🔧 4. All Embedded Tools Supported

"You can install everything — GCC, Make, GDB, Git, Python — all with one command.
No complex setups, no drivers."

---

### 🔄 5. File Sharing Between Windows & Linux

"You can keep your code in Windows folders, open it in VS Code, and compile it from WSL.
It’s seamless — both systems share files easily."

---

### 🧰 6. Simple for Beginners

"To install, just open PowerShell and type:

```bash
wsl --install
```

That’s it.
Ubuntu will automatically install inside Windows.
After that, you can open it anytime from your Start menu."

---

### 🚀 7. Real Industry Workflow

"Even professional engineers use this combo — VS Code + WSL + GCC + Git.
That’s why this course will also follow the same workflow."

---

## 🧭 **3. Navigating the Linux File System — 45:00 to 1:00:00**

"Alright, once you open WSL and see the Linux terminal, you’ll notice it looks like this:

```
boss@DESKTOP-xxxx:~$
```

That’s your Linux environment.
Now let’s learn a few commands to move around."

---

### 💻 Common Commands

| Command        | Description             |
| -------------- | ----------------------- |
| `pwd`          | Shows current directory |
| `ls`           | Lists files             |
| `cd folder`    | Moves into a folder     |
| `mkdir folder` | Creates a folder        |
| `rm file`      | Removes a file          |
| `clear`        | Clears terminal         |

---

### 🧩 Example Demo

"Let’s try this:

```bash
pwd
ls
mkdir test
cd test
```

You just created and entered a new folder inside Linux.
This is the basic movement you’ll use every day."

---

## ⚙️ **4. Setting Up GCC Compiler — 1:00:00 to 1:15:00**

"Now let’s set up the compiler — **GCC**.

GCC means *GNU Compiler Collection*.
It’s what converts your `.c` file into machine code that the microcontroller can understand."

---

### 🔧 Installation Steps

```bash
wsl           # opens Ubuntu
sudo apt update
sudo apt install gcc
```

"After that, you can check the version with:"

```bash
gcc --version
```

"If you see version details, you’re good to go."

---

## 💻 **5. Writing and Running a C Program — 1:15:00 to 1:30:00**

"Now, let’s write our first Linux-based C program."

---

### Step 1 — Create a File

```bash
nano hello.c
```

*(Explain)*
"`nano` is a simple text editor that works right inside the terminal."

---

### Step 2 — Type This Code

```c
#include <stdio.h>

int main() {
    printf("Hello, Embedded Linux!\n");
    return 0;
}
```

---

### Step 3 — Save and Exit

* Press `Ctrl + O` to save
* Press `Enter` to confirm
* Press `Ctrl + X` to exit

---

### Step 4 — Compile

```bash
gcc hello.c -o hello
```

*(Explain)*
"This compiles your source code and creates an output file named `hello`."

---

### Step 5 — Run

```bash
./hello.exe
```

✅ Output:

```
Hello, Embedded Linux!
```

*(Cheerfully)*
"There you go! You just ran your first program inside Linux."

---

## 🔍 **6. Understanding Compilation Steps — 1:30:00 to 1:40:00**

"Now let’s understand what happens behind that single GCC command."

| Step          | Command                     | Description                |
| ------------- | --------------------------- | -------------------------- |
| Preprocessing | `gcc -E hello.c -o hello.i` | Expands macros and headers |
| Compilation   | `gcc -S hello.i -o hello.s` | Converts to assembly       |
| Assembly      | `gcc -c hello.s -o hello.o` | Converts to object code    |
| Linking       | `gcc hello.o -o hello.exe`  | Final executable           |

"Each step transforms your code closer to machine language.
When we work with embedded systems, we’ll also use cross-compilers that do the same, but for ARM processors."

---

## 🎓 **7. Assignments & Practice — 1:40:00 to 1:55:00**

"Now, before we finish, I want you to try these small exercises."

| Level     | Task                                 | Hint                    |
| --------- | ------------------------------------ | ----------------------- |
| 🟢 Easy   | Print your name                      | Use `printf()`          |
| 🟡 Medium | Take two numbers and print their sum | Use `scanf()` for input |

"Try running each program, compile it with GCC, and make sure it runs successfully."

---

## 🧾 **8. Recap — 1:55:00 to 2:00:00**

"Alright, let’s summarize everything we learned today:

✅ Why Linux is the standard for embedded systems
✅ Why WSL Ubuntu is perfect for beginners
✅ How to navigate inside Linux
✅ How to install and use GCC
✅ How the compilation process works
✅ And finally, how to write and run your own C program.

Before you start blinking LEDs or reading sensors, it’s very important to first understand this Linux workflow.

Once you’re confident with Linux commands and GCC, everything else in embedded will feel easy."

---

🎤 **Closing Line:**

"Remember this line —

> *Before you blink an LED, you must first learn to compile code in Linux.*

This is the foundation of every embedded engineer."

---
