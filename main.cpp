#include "UserInterface.h"
#include "ExpenseManager.h"
#include <iostream>
#include <string>

int main() {
    ExpenseManager expenseManager;
    StorageManager storageManager;
    UserInterface ui(expenseManager, storageManager);

    // Load expenses at the start
    try {
        std::vector<Expense> loadedExpenses = storageManager.loadExpenses();
        for (size_t i = 0; i < loadedExpenses.size(); i++) {
            expenseManager.addExpense(loadedExpenses[i]);
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Failed to load expenses: " << e.what() << std::endl;
    }

    ui.mainMenu();

    // Save expenses before exiting
    storageManager.saveExpenses(expenseManager.getAllExpenses());

    return 0;
}