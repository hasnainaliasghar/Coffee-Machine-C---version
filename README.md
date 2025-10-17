# ☕ Coffee Machine Simulator

A **C++ console-based coffee vending machine** that simulates ordering coffee, handling payments, tracking resources, and recording daily sales.  
This project demonstrates **file handling**, **structs**, **loops**, **conditions**, and **persistent data storage** in C++.

---

## 🚀 Features

- **Three Coffee Options**
  - ☕ Espresso – Rs.150  
  - 🥛 Latte – Rs.250  
  - 🍫 Cappuccino – Rs.300
- **Resource Tracking** – checks water, milk, and coffee availability.
- **Payment Simulation** – accepts entered cash and returns change.
- **Bill Generation** – prints a formatted bill with order number.
- **Persistent Data**
  - `Today.txt` → daily sales log  
  - `account.txt` → total revenue  
  - `TotalSale.txt` → total cups sold
- **Admin Commands**
  - `report` → view remaining resources and earnings  
  - `off` → safely shut down the machine

---

## 🧠 Program Flow

1. Display welcome ASCII banner  
2. Show coffee menu  
3. Prompt user for input  
   - Enter `espresso`, `latte`, or `cappuccino` → place order  
   - Enter `report` → see machine status  
   - Enter `off` → shut down  
4. Check if resources are sufficient  
5. Request payment  
6. Confirm order (Y/N)  
7. On confirmation  
   - Deduct ingredients  
   - Print receipt  
   - Save transaction to file  
   - Update total sales  
8. On cancellation → refund money

---

## 📁 File Descriptions

| File | Purpose |
|------|----------|
| `main.cpp` | Main program source code |
| `account.txt` | Stores total balance (machine earnings) |
| `Today.txt` | Logs current day’s sales |
| `TotalSale.txt` | Tracks total quantity sold for each drink |

---

## 🧾 Example Output

Welcome to Coffee Making Machine!

Espresso Rs.150
Latte Rs.250
Cappuccino Rs.300

What would you like?: latte
Insert Money: 300
Do you want to confirm this Order?(Y/N): y

----------Bill----------
Coffee Making Machine
Date: 22-05-2025
Order number: 1
Description Unit Price
latte Rs. 250
Change Given: Rs. 50

Here is your latte ☕. Enjoy!

## 📄 Documnetation

[Coffee_Machine_Program_Documentation.pdf](https://github.com/user-attachments/files/22005408/Coffee_Machine_Program_Documentation.pdf)
