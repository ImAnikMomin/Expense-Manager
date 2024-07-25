#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "Expense.h"
#include <vector>
#include <string>

class StorageManager {
public:
    void saveExpenses(const std::vector<Expense>& expenses);
    std::vector<Expense> loadExpenses();

private:
    std::string fileName;
};

#endif // STORAGEMANAGER_H
