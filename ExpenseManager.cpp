#include "ExpenseManager.h"

void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

std::vector<Expense> ExpenseManager::getExpensesByCategory(const std::string& category) {
    // Implementation
    std::vector<Expense> result;
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getCategory() == category) {
            result.push_back(expenses[i]);
        }
    }
    return result;
}

std::vector<Expense> ExpenseManager::getAllExpenses() {
    return expenses;
}

double ExpenseManager::getTotalExpenses() {
    double total = 0.0;
    for (size_t i = 0; i < expenses.size(); i++) {
        total += expenses[i].getAmount();
    }
    return total;
}
std::vector<Expense> ExpenseManager::getExpensesByDate(const std::string& date) {
    std::vector<Expense> result;
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getDate() == date) {
            result.push_back(expenses[i]);
        }
    }
    return result;
}

double ExpenseManager::getTotalExpensesByCategory(const std::string& category) {
    double total = 0;
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getCategory() == category) {
            total += expenses[i].getAmount();
        }
    }
    return total;
}

double ExpenseManager::getTotalExpensesByDate(const std::string& date) {
    double total = 0;
    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getDate() == date) {
            total += expenses[i].getAmount();
        }
    }
    return total;
}
