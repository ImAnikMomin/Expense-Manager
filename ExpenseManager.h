#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include <vector>

class ExpenseManager {
public:
    void addExpense(const Expense& expense);
    std::vector<Expense> getExpensesByCategory(const std::string& category);
    std::vector<Expense> getAllExpenses();
    double getTotalExpenses();
    std::vector<Expense> getExpensesByDate(const std::string& date);
    double getTotalExpensesByCategory(const std::string& category);
    double getTotalExpensesByDate(const std::string& date);

private:
    std::vector<Expense> expenses;
};

#endif // EXPENSEMANAGER_H
