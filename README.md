<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/Course-Programming_Fundamentals-green?style=for-the-badge" alt="PF"/>
  <img src="https://img.shields.io/badge/University-Superior_University-red?style=for-the-badge" alt="Superior University"/>
</p>

<h1 align="center">📘 Programming Fundamentals (PF)</h1>

<p align="center">
  A complete collection of all my <strong>Programming Fundamentals</strong> coursework — assignments, practice programs, and the semester project — written in <strong>C++</strong> during my studies at Superior University.
</p>

---

## 👤 Author

| Detail | Info |
|---|---|
| **Name** | Muhammad Ibrahim |
| **Roll Number** | 023 |
| **Section** | SE-2A |
| **Program** | BS Software Engineering |
| **University** | Superior University |
| **Course** | Programming Fundamentals |

---

## 📂 Repository Structure

```
PF/
├── assignments/
│   ├── Assignment-1-pf/          # 20 programs — conditionals, loops, basic logic
│   ├── Assignment-2-pf/          # 6 programs — menu-driven console apps
│   └── Assignment-4/             # 24 programs — functions, arrays, strings, 2D arrays
│       ├── Part-1/
│       ├── Part-2/
│       ├── Part-3/
│       └── Part-4/
│
├── PF-Project-BMS/               # 🏦 Semester Project — Bank Management System
│   ├── main.cpp
│   ├── headers/                  # 7 header files
│   ├── modules/                  # 5 implementation files
│   ├── Documentation-MD.md       # Full technical documentation
│   ├── Documentation-pdf.pdf     # PDF version of documentation
│   └── README.md                 # Detailed project README
│
└── README.md                     # You are here
```

---

## 📋 Contents at a Glance

### 📝 Assignments

<details>
<summary><b>Assignment 1</b> — Conditionals, Loops & Basic Logic (20 Questions)</summary>

<br>

Covers foundational C++ concepts including `if/else` statements, `switch` cases, loops (`for`, `while`, `do-while`), arithmetic operations, and basic input validation.

**Topics:** Variable assignment, temperature validation, number comparison, grade calculators, even/odd detection, multiplication tables, factorial, Fibonacci series, prime numbers, palindrome checking, and more.

**📁 Path:** [`assignments/Assignment-1-pf/`](assignments/Assignment-1-pf/)

</details>

<details>
<summary><b>Assignment 2</b> — Menu-Driven Console Applications (6 Programs)</summary>

<br>

Focuses on building larger, real-world simulation programs with interactive menus, user authentication, and structured output.

**Programs include:**
- Student Diary System (CRUD operations with login)
- LESCO Electricity Billing System (slab-based billing with GST)
- Restaurant POS System
- Library Management System
- Hospital Management System
- Parking Management System

**📁 Path:** [`assignments/Assignment-2-pf/`](assignments/Assignment-2-pf/)

</details>

<details>
<summary><b>Assignment 4</b> — Functions, Arrays, Strings & 2D Arrays (24 Programs)</summary>

<br>

Divided into 4 parts, this assignment covers modular programming using functions, 1D and 2D array operations, and C-string manipulation.

| Part | Focus Area | Programs |
|---|---|---|
| Part 1 | Functions + 1D Arrays | Average, Min/Max, Power, Voltage, Cricket Search, Word Length |
| Part 2 | Functions + Logic | 2nd Highest/Lowest, Sum Array, Temp Converter, Leap Year, Vowel Counter, Alphabetical Sort |
| Part 3 | 2D Arrays + Strings | Even/Odd Count, 2D Display, GCD, Strike Rate, String Length, Word Copy |
| Part 4 | 2D Array Ops + Strings | 2D Sum, 2D Subtract, Area Calculator, Bowling Average, Vertical Printer, Reverse Word |

**📁 Path:** [`assignments/Assignment-4/`](assignments/Assignment-4/)

</details>

---

### 🏦 Semester Project — Bank Management System (BMS)

The flagship project of this repository. A fully-featured, console-based banking system built in **procedural C++** with three distinct user interfaces:

| Module | Key Features |
|---|---|
| **🔐 Admin Portal** | Customer CRUD, deposits, withdrawals, transfers, transaction audit log, bank statistics, account lock/unlock |
| **👤 Customer Section** | Self-registration, secure login (3-attempt lockout), deposits, withdrawals, fund transfers, Zakat auto-deduction |
| **🏧 ATM Simulation** | PIN authentication, balance inquiry, cash withdrawal, fast cash (preset amounts), mini statement, PIN change |

**Highlights:**
- Masked password & PIN input
- Persistent file-based storage (pipe-delimited `.txt` files)
- Color-coded terminal UI with animations
- Islamic banking feature — automatic 2.5% Zakat deduction above PKR 3,000,000
- Comprehensive [technical documentation](PF-Project-BMS/Documentation-MD.md) included

**📁 Path:** [`PF-Project-BMS/`](PF-Project-BMS/) — *See the [full project README](PF-Project-BMS/README.md) for build instructions and details.*

---

## ⚙️ Tech Stack & Tools

| Component | Details |
|---|---|
| Language | C++ (Procedural — no OOP/classes) |
| Compiler | MinGW GCC (g++) |
| Platform | Windows Console |
| IDE | VS Code |
| Version Control | Git & GitHub |

---

## 🚀 How to Compile & Run

All programs can be compiled using `g++` from the MinGW GCC toolchain:

```bash
# Single-file programs (assignments)
g++ -o output.exe "question 1.cpp"
./output.exe

# Multi-file project (BMS)
cd PF-Project-BMS
g++ -o bms.exe main.cpp modules/utils.cpp modules/filehandling.cpp modules/admin.cpp modules/customer.cpp modules/atm.cpp
./bms.exe
```

---

## 📊 Course Topics Covered

| Topic | Where |
|---|---|
| Variables, Data Types & Operators | Assignment 1 |
| Conditional Statements (`if/else`, `switch`) | Assignment 1 |
| Loops (`for`, `while`, `do-while`) | Assignment 1, 2 |
| Functions (with & without return values) | Assignment 4 |
| 1D & 2D Arrays | Assignment 4 |
| C-Strings & String Manipulation | Assignment 4 |
| File Handling (`ifstream`, `ofstream`) | BMS Project |
| Structs | BMS Project |
| Modular Programming (headers + source files) | BMS Project |
| Input Validation & Error Handling | All |

---

## 📝 License

This repository contains academic coursework created for **Programming Fundamentals** at **Superior University**. Feel free to use it as a reference for learning.

---

<p align="center">
  <strong>Built with ❤️ by Muhammad Ibrahim</strong>
</p>
