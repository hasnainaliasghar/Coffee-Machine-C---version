Coffee Vending Machine Program Documentation
Overview
This C++ program simulates a coffee vending machine that offers three types of drinks: Espresso, Latte, and Cappuccino. It allows users to select a drink, check resource availability, insert payment, receive change, and view a printed bill. Additionally, the machine maintains sales records and ingredient levels.
Key Features
•Interactive CLI for user input.
•Drink selection and validation.
•Ingredient availability check.
•Coin processing and change calculation.
•Bill generation and order confirmation.
•Persistent sales data storage (Today.txt, TotalSale.txt).
•Maintains total cash in the machine (account.txt).
•Shutdown option via 'off' command.
•Reports of remaining ingredients and money.
Data Structures
struct Drink {
string name;
int water;
int milk;
int coffee;
double cash;
};
File Usage
•Today.txt - Stores daily sales with drink names and prices.
•TotalSale.txt - Maintains cumulative counts of drinks sold.
•account.txt - Stores total money collected by the machine.
Function Descriptions
•art(): Displays an ASCII logo.
•is_resources_sufficient(): Checks if ingredients are sufficient for the drink.
•process_coins(): Accepts and returns inserted money.
•displaybill(): Prints a receipt with order info and change.
•deductingredients(): Deducts the used ingredients.
•datafunc(): Appends sale record and updates account.
•total_sale(): Updates the count of drinks sold.
Main Function Flow
1.Loads the account balance.
2.Defines menu with drink options.
3.Displays menu and prompts user input.
4.Handles special inputs ('report', 'off').
5.Validates drink name.
6.Checks resources and payment.
7.Deducts resources and confirms order.
8.Updates files with transaction data.
Error Handling & Input Validation
•Invalid drink names are rejected.
•Insufficient ingredients or money are reported.
•Invalid confirmation input is re-prompted.
Enhancements Suggestions
•Use constants or enums for drink names.
•Persist resources between runs.
•Add exception handling for files.
•Improve interface with GUI or menu system.
Sample Output
Conclusion
This program provides a complete simulation of a coffee vending machine with order processing, resource management, and sales tracking, making it a great educational project for file handling, structs, and user interaction in C++. Project by,
Abdullah Hussain Khan 70174525
Hasnain Ali Asghar 70173459
