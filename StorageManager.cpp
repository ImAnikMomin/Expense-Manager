#include "StorageManager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>

void StorageManager::saveExpenses(const std::vector<Expense>& expenses) {
    std::ofstream file("expenses.txt");
    if (!file.is_open()) {
        throw std::runtime_error("File does not exist.");
        return;
    }
    for (size_t i = 0; i < expenses.size(); i++) {
        file << expenses[i].getAmount() << ","
            << expenses[i].getCategory() << ","
            << expenses[i].getDate() << ","
            << expenses[i].getDescription() << std::endl;
    }
    file.close();
}

std::vector<Expense> StorageManager::loadExpenses() {
    std::vector<Expense> expenses;
    std::ifstream file("expenses.txt");
    if (!file.is_open()) {
        throw std::runtime_error("File does not exist.");
    }
    std::string line;
    while (getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> data;

        while (std::getline(ss, token, ',')) {
            data.push_back(token);
        }

        if (data.size() == 4) {
            double amount = std::stod(data[0]);
            std::string category = data[1];
            std::string date = data[2];
            std::string description = data[3];

            expenses.emplace_back(amount, category, date, description);
        }
    }
    file.close();
    return expenses;
}