# 📟 Smart ATM Simulator (C Programming Project)

A console-based ATM Simulator built in **C**, designed to replicate essential banking operations including secure PIN verification, withdrawals, deposits, balance enquiry, PIN updates, and timestamped transaction history.

---

## 🚀 Project Overview

This project simulates the internal workflow of an ATM machine.  
It demonstrates:

- Secure 4-digit user authentication  
- Basic banking transactions  
- In-memory transaction logging with timestamps  
- Console color formatting for UI  
- Beep sounds for a more realistic ATM feel  

---

## 🔐 Key Features

### 🧾 1. User Authentication

- 4-digit PIN entry (masked input using `_getch()`)  
- User validation using a `struct User` array  
- Error beeps for invalid PIN  

---

### 💳 2. Banking Functions

| Function               | Description                                      |
|------------------------|--------------------------------------------------|
| **Withdraw**           | Deducts amount + logs transaction                |
| **Deposit**            | Adds balance + logs transaction                  |
| **Balance Enquiry**    | Displays current account balance                 |
| **Transaction History**| Shows recent timestamped transaction records     |
| **Change PIN**         | Secure PIN update for existing user              |
| **Exit**               | Ends the ATM session                             |

---

## 🧠 Technical Concepts Used

- **Structures** (`struct User`)  
- **Arrays & loops** for managing multiple accounts  
- **Time library** (`time.h`) for timestamps  
- **Windows API** (`windows.h`) for `Beep()` and `Sleep()`  
- **Input masking** using `<conio.h>` and `_getch()`  
- **Modular function design** (separate functions for each feature)  
- **Error handling** for invalid options and insufficient balance  

---

## 📂 Project Structure

```text
smart-atm-simulator-c/
│
├── src/
│   └── main.c                      # Complete ATM logic
│
├── docs/
│   ├── ATM_Project_Presentation.pptx
│   └── ATM_Report.pdf
│
├── demo/
│   ├── simulation.mp4              # Code execution demo
│   └── output.mp4                  # Final output demo
│
├── assets/
│   └── screenshots/
│       ├── menu.png
│       ├── login.png
│       └── history.png
│
└── README.md

```text
2025-05-30 12:34:44 – Withdraw: Rs. 100.00
2025-05-30 19:19:59 – Deposit: Rs. 300.00
