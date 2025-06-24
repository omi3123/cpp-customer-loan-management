#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Customer {
public:
    string name;
    double balance;
    bool loan;
    Customer(string n, double b) {
        name = n;
        balance = b;
        loan = false;
    }
    void display() const {
        cout << "Customer Name: " << name 
             << " Balance: $" << balance 
             << " Loan: " << (loan ? "Yes" : "No") << endl;
    }
};
class Loan {
public:
    double amount;
    double interest_rate;
    int term;
    bool repaid;
    Loan(double amt, double rate, int t) {
        amount = amt;
        interest_rate = rate;
        term = t;
        repaid = false;
    }
    void display() const {
        cout << "Loan of amount: " << amount 
             << " at Interest rate: " << interest_rate 
             << "% for " << term << " years" << endl;
    }
};
class Bank {
private:
    vector<Customer> customers;
public:
    string add_customer(string name, double balance) {
        Customer c(name, balance);
        customers.push_back(c);
        return "Customer: " + name + " added";
    }
    void approve_loan(string customer_name, double amount, double interest_rate, int term) {
        bool found = false;
        for (Customer& c : customers) {
            if (c.name == customer_name) {
                Loan loan(amount, interest_rate, term);
                c.loan = true;
                cout << "Loan approved for " << customer_name << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << customer_name << " not found" << endl;
        }
    }
    void view_customers() const {
        for (const Customer& c : customers) {
            c.display();
        }
    }
};
int main() {
    Bank bank;
    bank.add_customer("Ahmad", 5000);
    bank.approve_loan("Ali", 10000, 5, 3);
    bank.view_customers();
    return 0;
}