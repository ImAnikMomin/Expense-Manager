#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
public:
    Expense(double amount, const std::string& category, const std::string& date, const std::string& description);

    double getAmount() const;
    std::string getCategory() const;
    std::string getDate() const;
    std::string getDescription() const;

    void setAmount(double amount);
    void setCategory(const std::string& category);
    void setDate(const std::string& date);
    void setDescription(const std::string& description);

private:
    double amount;
    std::string category;
    std::string date;
    std::string description;
};

#endif // EXPENSE_H
