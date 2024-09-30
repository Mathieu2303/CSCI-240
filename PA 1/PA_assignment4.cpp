/*  Program: Exercise 4
    Author: Mathieu Partain-Martinez
    Class: CSCI 240
    Date: 09/03/ 2024  
    Description: Class called credit card that can take add charges, take payments and add interest
    Exception(s): N/A
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class CreditCard {
  private:
    string customer;          // name of the customer (e.g., "John Bowman")
    string bank;              // name of the bank (e.g., "California Savings")
    string account;           // account identifier (e.g., "5391 0375 9387 5309")
    int limit;                // credit limit (measured in dollars)

  protected:
    double balance;           // current balance (measured in dollars)
    double interest;

  public:
    // Constructs a new credit card. The initial balance is 0.0 by default.
    CreditCard(string cust, string bk, string acnt, int lim, double initial_bal = 0.0, double monthlyInterest = 15)
        : customer{cust}, bank{bk}, account{acnt}, limit{lim}, balance{initial_bal}, interest{monthlyInterest} {}

    // ------------- Accessors -------------
    string get_customer() const { return customer; }
    string get_bank() const { return bank; }
    string get_account() const { return account; }
    int get_limit() const { return limit; }
    double get_balance() const { return balance; }

    // ------------- Mutators -------------
    void addMonthlyInterest(){ // void because it modifies the value directly and does not need to return a value
        double monthlyInterest = interest /12/100; // percentange interest rate applied for each month
        double totalInterest = balance * monthlyInterest;
        balance += totalInterest; // adds interest to the balance2
    }
    // Charges price to card if within credit limit, and returns whether successful
    bool charge(double price) {
        if (price + balance > limit)                      // if charge would surpass limit
            return false;                                 // refuse the charge
        // at this point, the charge is successful
        balance += price;                                 // update the balance
        return true;                                      // announce the good news
    }

    // Processes customer payment to reduce the balance
    void make_payment(double amount) { balance -= amount; }

    // ---------- Overloaded output operator (as friend) ---------
    friend ostream& operator<<(ostream& out, const CreditCard& c) {
        out << "Customer = " << c.customer << endl;
        out << "Bank = " << c.bank << endl;
        out << "Account = " << c.account << endl;
        out << "Balance = " << c.balance << endl;
        out << "Limit = " << c.limit << endl;
        return out;
    }
};

int main(){
    CreditCard card1("John Doe", "Chase", "0000 0000 0000 0000", 5000);
    CreditCard card2("Jane Doe", "Wells Fargo","1234 1234 1234 1234", 3000);
    double amountCharged;
   
    for (int i = 0; i <= 2; i++){
        cout << "Month: " << i + 1 << endl;

        cout << "enter charge for card 1: ";
        cin >> amountCharged;
        card1.charge(amountCharged);
    
        cout << "make payment for card 1: ";
        cin >> amountCharged;
        card1.make_payment(amountCharged);
       
        cout << "enter charge for card 2: ";
        cin >> amountCharged;
        card2.charge(amountCharged);

        cout << "make payment for card 2: ";
        cin >> amountCharged;
        card2.make_payment(amountCharged);

        card1.addMonthlyInterest();
        card2.addMonthlyInterest();
    }
    
    cout << card1;
    cout << card2;
  
}