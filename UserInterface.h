#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "StorageManager.h"

#include "ExpenseManager.h"

class UserInterface {
public:
    UserInterface(ExpenseManager& manager, StorageManager& storageMgr);
    void mainMenu();

private:
    ExpenseManager& expenseManager;
    StorageManager& storageManager;

    void addExpense();
    void viewExpenses();
    void showTotalExpenses();
    void getExpensesByCategory();
    void getExpensesByDate();
};

#endif // USERINTERFACE_H
