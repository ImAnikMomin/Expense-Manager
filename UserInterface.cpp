#include "UserInterface.h"
#include <iostream>
#include "Utils.h"

UserInterface::UserInterface(ExpenseManager& manager, StorageManager& storageMgr) : expenseManager(manager), storageManager(storageMgr) {}

void UserInterface::mainMenu() {
    std::string choice;
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\n----- Expense Tracker -----\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Show Total Expenses\n";
        std::cout << "4. View Expenses by Category\n";
        std::cout << "5. View Expenses by Date\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "1") {
            addExpense();
        }
        else if (choice == "2") {
            viewExpenses();
        }
        else if (choice == "3") {
            showTotalExpenses();
        }
        else if (choice == "4") {
            getExpensesByCategory();
        }
        else if (choice == "5") {
            getExpensesByDate();
        }
        else if (choice == "6") {
            storageManager.saveExpenses(expenseManager.getAllExpenses());
            isRunning = false;
        }
        else {
            std::cout << "Invalid choice, please try again.\n";
        }
    }
}
void UserInterface::addExpense() {
        std::string category, description, date;
        double amount;

        std::cout << "Enter expense category: ";
        std::cin >> category;

        std::cout << "Enter expense description: ";
        std::cin.ignore();
        std::getline(std::cin, description);
        date = Utils::getCurrentDateMMDDYYYY();

        std::cout << "Enter expense amount: ";
        std::cin >> amount;

        Expense newExpense(amount, category, date, description);  
        expenseManager.addExpense(newExpense);

        std::cout << "Expense added successfully.\n";
        storageManager.saveExpenses(expenseManager.getAllExpenses());
}
void UserInterface::viewExpenses() {
    std::vector<Expense> expenses = expenseManager.getAllExpenses();
    if (expenses.empty()) {
        std::cout << "No expenses recorded.\n";
        return;
    }

    std::cout << "\nExpenses:\n";
    for (size_t i = 0; i < expenses.size(); i++) {
        std::cout << "Category: " << expenses[i].getCategory()
            << ", Description: " << expenses[i].getDescription()
            << ", Date: " << expenses[i].getDate()
            << ", Amount: " << expenses[i].getAmount() << "\n";
    }
}
void UserInterface::showTotalExpenses() {
    double total = expenseManager.getTotalExpenses();
    std::cout << "Total expenses: " << total << "\n";
}
void UserInterface::getExpensesByCategory() {
    std::string category;
    std::cout << "Enter expense category: ";
    std::cin >> category;

    std::vector<Expense> expenses = expenseManager.getExpensesByCategory(category);
    double total = expenseManager.getTotalExpensesByCategory(category);

    std::cout << "\nExpenses for category '" << category << "':\n";
    for (int i = 0; i < expenses.size(); i++) {
        std::cout << "Description: " << expenses[i].getDescription()
            << ", Date: " << expenses[i].getDate()
            << ", Amount: " << expenses[i].getAmount() << "\n";
    }
    std::cout << "Total expenses for category '" << category << "': " << total << "\n";
}
void UserInterface::getExpensesByDate() {
    std::string date;
    std::cout << "Enter expense date (format MMDDYYYY): ";
    std::cin >> date;

    std::vector<Expense> expenses = expenseManager.getExpensesByDate(date);
    double total = expenseManager.getTotalExpensesByDate(date);

    std::cout << "\nExpenses for date '" << date << "':\n";
    for (int i = 0; i < expenses.size(); i++) {
        std::cout << "Category: " << expenses[i].getCategory()
            << ", Description: " << expenses[i].getDescription()
            << ", Amount: " << expenses[i].getAmount() << "\n";
    }
    std::cout << "Total expenses for date '" << date << "': " << total << "\n";
}