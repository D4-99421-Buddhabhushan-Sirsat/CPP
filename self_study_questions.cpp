#include<iostream>
using namespace std;

class BankAccount{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, string accHolderName, double initialBalance){
        this->accountNumber = accNum;
        this->accountHolderName = accHolderName;
        this->balance = initialBalance;
    }

    void deposit(double amount){
        if(amount>0) this->balance += amount;
        else cout << "Deposit amount must be positive." << endl;
    }

    void withdraw(double amount){
        if(amount>0 && amount <= this->balance) this->balance -= amount;
        else cout << "Invalid withdrawal amount." << endl;
    }

    void displayAccountDetails() const{
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Account Holder Name: " << this->accountHolderName << endl;
        cout << "Balance: INR " << this->balance << endl;
    }
};

int main(){
     BankAccount a1(123, "Buddhabhushan Sirsat", 2000.00);
     a1.displayAccountDetails();

     a1.deposit(500.00);
     a1.displayAccountDetails();

    a1.withdraw(300.00);    
    a1.displayAccountDetails();

    return 0;
}