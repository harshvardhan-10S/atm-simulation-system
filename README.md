# 📟 Smart ATM Simulator (C Project)

A console-based ATM Simulator built in **C**, designed to replicate essential banking operations such as secure PIN verification, withdrawals, deposits, balance enquiry, PIN change, and basic transaction history.

---

## 📘 1. Project Overview

The project demonstrates how an ATM operates at a logical level using structured programming in C.

🔹 Secure 4-digit PIN authentication  
🔹 Modular code structure  
🔹 Console-based UI  
🔹 Basic transaction logging  
🔹 Clean and simple workflow  

---

## 🧩 2. Features

### 🔐 User Functions
✔️ 4-digit PIN authentication  
✔️ Masked PIN input (`****`)  
✔️ Withdraw (with balance validation)  
✔️ Deposit  
✔️ Balance enquiry  
✔️ Transaction summary  
✔️ Change PIN  
✔️ Exit session safely  

---

## 🧠 3. System Design

### 🔹 Logical Components
- 🧾 **User Data Handling:** struct-based account storage  
- 🔐 **Authentication Module:** masked PIN + validation  
- 💸 **Transaction Processing:** withdraw/deposit logic  
- 📋 **Menu Handling:** clean switch-case based flow  
- 🔑 **PIN Management:** secure PIN update  

---

## 🛠️ 4. Technical Details

### 🖥️ Language and Tools
- 🔹 C Programming  
- 🔹 GCC Compiler  
- 🔹 Code::Blocks / VS Code  

### 💡 Concepts Used
- 📌 Structures (`struct`)  
- 📌 Functions (modular approach)  
- 📌 Loops & condition checks  
- 📌 Input handling  
- 📌 Optional: `<conio.h>`, `<time.h>`, `<windows.h>`  

---

## 🖥️ 5. Sample Output

### 🔵 Login & Menu

=== Smart ATM Simulator ===
Insert Card...
Enter 4-digit PIN: ****
Login successful.

1. Withdraw
2. Deposit
3. Balance Enquiry
4. Transaction Summary
5. Change PIN
6. Exit

### 🧾 Transaction Summary

Recent Transactions:
- Withdraw: Rs. 400.00
- Deposit:  Rs. 100.00
- Withdraw: Rs. 300.00

### 🟩 Deposit Example

Enter amount to deposit: 500
Amount deposited successfully.

### 📊 Balance Enquiry

Your current balance is: Rs. 3040.00

### 🔐 PIN Change

Enter old PIN: ****
Enter new PIN: ****
PIN changed successfully.

---

## 📁 6. Project Structure

```text
smart-atm-simulator-c/
│
├── src/
│   └── main.c
│
├── docs/
│   ├── ATM_Project_Presentation.pptx
│   └── ATM_Report.pdf
│
├── demo/
│   ├── ATM_Simulation.mp4
│   └── ATM_Output.mp4
│
└── README.md

---


