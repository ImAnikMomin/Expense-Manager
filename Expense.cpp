#include "Expense.h"

Expense::Expense(double amount, const std::string& category, const std::string& date, const std::string& description)
    : amount(amount), category(category), date(date), description(description) {}

double Expense::getAmount() const {
    return amount;
}

std::string Expense::getCategory() const {
    return category;
}

std::string Expense::getDate() const {
    return date;
}

std::string Expense::getDescription() const {
    return description; 
}

void Expense::setAmount(double newamount) {
    amount = newamount;
}

void Expense::setCategory(const std::string& newcategory) {
    category = newcategory;
}

void Expense::setDate(const std::string& newdate) {
    date = newdate;
}

void Expense::setDescription(const std::string& newdescription) {
    description = newdescription;
}