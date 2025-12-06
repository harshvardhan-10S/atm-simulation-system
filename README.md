# Smart ATM Simulator (C Project)

This project is a console-based ATM simulation system developed in C.  
It replicates the core functionality of an ATM, including PIN authentication, cash withdrawal, deposit, balance enquiry, PIN change, and basic transaction history.

---

## 1. Project Overview

The objective of this project is to demonstrate how an ATM system works at a logical level using structured programming in C.  
The system focuses on:

- Secure user authentication using a 4-digit PIN  
- Clear and simple banking operations  
- Well-structured, modular code  
- Console-based user interface with basic feedback

This project is suitable as an academic mini-project and as a demonstration of C programming fundamentals.

---

## 2. Features

### 2.1 User Functions

- **PIN Authentication**  
  - 4-digit PIN entry  
  - Masked input (PIN not visible on screen)  
  - Basic validation for incorrect attempts  

- **Withdraw**  
  - Validates available balance  
  - Deducts amount from account  

- **Deposit**  
  - Adds amount to current balance  

- **Balance Enquiry**  
  - Displays current account balance  

- **Transaction Summary (Basic)**  
  - Shows recent operations in a readable text format  

- **Change PIN**  
  - Allows user to update PIN after verifying the old one  

- **Exit**  
  - Safely terminates the session  

---

## 3. System Design

### 3.1 Logical Components

The project is organized into the following logical parts:

- **User Data Handling**  
  - Uses a `struct` to store account details (e.g., PIN, balance).  

- **Authentication Module**  
  - Verifies PIN input against stored data.  
  - Uses masked input to hide PIN characters.  

- **Transaction Processing**  
  - Performs deposit and withdrawal operations.  
  - Includes basic validation (e.g., sufficient balance).  

- **Display and Menu Handling**  
  - Prints the main menu and reads user choices.  
  - Handles invalid options with error messages.  

- **PIN Management**  
  - Verifies current PIN before allowing change.  

---

## 4. Technical Details

### 4.1 Language and Tools

- Programming Language: **C**
- Recommended IDE: **Code::Blocks** / **VS Code with GCC**
- Compiler: **GCC** or equivalent

### 4.2 Concepts Used

- Structures (`struct`)  
- Functions and modular programming  
- Loops and conditional statements  
- Basic input validation  
- Console input/output  
- Optional use of:
  - `<conio.h>` for masked input  
  - `<time.h>` for timestamps (if extended)

---

## 5. Project Structure (Suggested)

You can organize your repository as:

```text
smart-atm-simulator-c/
│
├── src/
│   └── main.c                  # Main ATM program in C
│
├── docs/
│   ├── ATM_Project_Presentation.pptx
│   └── ATM_Report.pdf
│
├── demo/
│   ├── ATM_Simulation.mp4      # Code execution / simulation video
│   └── ATM_Output.mp4          # Final output / usage demo
│
└── README.md
