#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

class Expense {
public:
    string category;
    double amount;
    string date;

    Expense(string cat, double amt, string dt) : category(cat), amount(amt), date(dt) {}

    void display() const {
        cout << left << setw(15) << category << setw(10) << amount << setw(15) << date << endl;
    }
};

class FinanceTracker {
private:
    vector<Expense> expenses;
    map<string, double> categoryTotals;

public:
    void addExpense(const string& category, double amount, const string& date) {
        expenses.emplace_back(category, amount, date);
        categoryTotals[category] += amount;
    }

    void generateReport() const {
        cout << "\nPersonal Finance Report\n" << string(30, '-') << endl;
        for (const auto& expense : expenses) {
            expense.display();
        }
        cout << "\nTotal by Category:\n";
        for (const auto& category : categoryTotals) {
            cout << left << setw(15) << category.first << category.second << endl;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Category,Amount,Date\n";
            for (const auto& expense : expenses) {
                file << expense.category << "," << expense.amount << "," << expense.date << "\n";
            }
            file.close();
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        string line, category, amountStr, date;
        double amount;
        if (file.is_open()) {
            getline(file, line);
            while (getline(file, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                category = line.substr(0, pos1);
                amountStr = line.substr(pos1 + 1, pos2 - pos1 - 1);
                date = line.substr(pos2 + 1);
                amount = stod(amountStr);
                addExpense(category, amount, date);
            }
            file.close();
        }
    }

    void displayMenu() {
        int choice;
        string category, date, filename;
        double amount;
        while (true) {
            cout << "\n1. Add Expense\n2. Generate Report\n3. Save to File\n4. Load from File\n5. Exit\nEnter choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter category: ";
                    cin >> category;
                    cout << "Enter amount: ";
                    cin >> amount;
                    cout << "Enter date (YYYY-MM-DD): ";
                    cin >> date;
                    addExpense(category, amount, date);
                    break;
                case 2:
                    generateReport();
                    break;
                case 3:
                    cout << "Enter filename to save: ";
                    cin >> filename;
                    saveToFile(filename);
                    break;
                case 4:
                    cout << "Enter filename to load: ";
                    cin >> filename;
                    loadFromFile(filename);
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice. Please try again.";
            }
        }
    }
};

int main() {
    FinanceTracker tracker;
    tracker.displayMenu();
    return 0;
}
