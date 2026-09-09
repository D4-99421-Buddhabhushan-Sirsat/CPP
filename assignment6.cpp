// Question 1:
/*
#include <iostream>
using namespace std;

class Product{
protected:
    int id;
    string title;
    int price;

public:
    Product(){
        this->id = 0;
        this->title = "";
        this->price = 0;
    }    

    Product(int id, string title, int price){
        this->id = id;
        this->title = title;
        this->price = price;    
    }

    virtual float calculateBill() = 0;

    virtual void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }

    virtual ~Product(){
    }
};

class Book : public Product{
private:
    string author;
    
public:
    Book() : Product(){
        this->author = "";
    }    

    Book(int id, string title, int price, string author)
        : Product(id, title, price) {
        this->author = author;
    }

    float calculateBill() override {
        return price * 0.9; // 10% discount
    }

    void display() override{
        Product::display();
        cout<<"Author: "<<author<<endl;
        cout << "Discount: 10%" << endl;
        cout << "Final Price: " << calculateBill() << endl;
    }
};

class Tape : public Product{
protected:
    string artist;
public:
    Tape() : Product() {
        this->artist = "";
    }    

    Tape(int id, string title, int price, string artist)
        : Product(id, title, price) {
        this->artist = artist;
    }

    float calculateBill() override {
        return price * 0.95; 
    }

    void display() override{
        Product :: display();
        cout<<"Artist: "<<artist<<endl;
        cout << "Discount: 5%" << endl;
        cout << "Final Price: " << calculateBill() << endl;
    }
};

int main(){

    Product *p1[3];

    for(int i=0; i<3; i++){
        cout<<"Select product type"<<endl;
        cout<<"1. Book"<<endl;
        cout<<"2. Tape"<<endl;
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;

        int id; 
        string title;
        int price;

        cout<<"Enter Id: ";
        cin>>id;
        cout<<"Enter Title: ";
        cin.ignore(); // To ignore the newline character left in the input buffer
        getline(cin, title);
        cout<<"Enter Price: ";
        cin>>price;     

        if(choice==1){
            string author;
            cout<<"Enter author: ";
            cin.ignore(); // To ignore the newline character left in the input buffer
            getline(cin, author);
            p1[i] = new Book(id, title, price, author);
        }
        else if(choice==2){
            string artist;
            cout<<"Enter artist: ";
            cin.ignore(); // To ignore the newline character left in the input buffer
            getline(cin, artist);
            p1[i] = new Tape(id, title, price, artist);
        }

        else cout<<"Invalid Choice !!!"<<endl;

    }

    cout<<"************************||************************"<<endl;

    cout<<"Displaying Product Details: "<<endl;
    int totalBill = 0;

    for(int i=0;i<3;i++){
        cout<<"Product "<<i+1<<":"<<endl;
        p1[i]->display();
        cout<<endl;
        totalBill += p1[i]->calculateBill();
    }
    
    cout<<"Total Bill: "<<totalBill<<endl;

    for(int i=0;i<3;i++){
        delete p1[i];
        p1[i] = NULL;
    }
    return 0;
}
*/


#include <iostream>
using namespace std;

// EMPLOYEE 
class Employee
{
private:
    int id;
    double salary;

public:
    Employee()
    {
        id = 0;
        salary = 0;
    }

    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return salary;
    }

    void accept()
    {
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "ID     : " << id << endl;
        cout << "Salary : " << salary << endl;
    }
};


// ================= MANAGER =================

class Manager : virtual public Employee
{
private:
    double bonus;

public:
    Manager()
    {
        bonus = 0;
    }

    Manager(int id, double salary, double bonus)
        : Employee(id, salary)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        Employee::accept();

        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void display()
    {
        Employee::display();

        cout << "Bonus  : " << bonus << endl;
    }

    void acceptManager()
    {
        accept();
    }

    void displayManager()
    {
        display();
    }
};


//  SALESMAN 

class Salesman : virtual public Employee
{
private:
    double commission;

public:
    Salesman()
    {
        commission = 0;
    }

    Salesman(int id, double salary, double commission)
        : Employee(id, salary)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }

    void accept()
    {
        Employee::accept();

        cout << "Enter Commission: ";
        cin >> commission;
    }

    void display()
    {
        Employee::display();

        cout << "Commission : " << commission << endl;
    }

    void acceptSalesman()
    {
        accept();
    }

    void displaySalesman()
    {
        display();
    }
};


//  SALESMANAGER 

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }

    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary),
          Manager(id, salary, bonus),
          Salesman(id, salary, commission)
    {
    }

    void accept()
    {
        int id;
        double salary;
        double bonus;
        double commission;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "Enter Bonus: ";
        cin >> bonus;

        cout << "Enter Commission: ";
        cin >> commission;

        Employee::setId(id);
        Employee::setSalary(salary);
        Manager::setBonus(bonus);
        Salesman::setCommission(commission);
    }

    void display()
    {
        cout << "ID         : " << Employee::getId() << endl;
        cout << "Salary     : " << Employee::getSalary() << endl;
        cout << "Bonus      : " << Manager::getBonus() << endl;
        cout << "Commission : " << Salesman::getCommission() << endl;
    }
};

int main()
{
    cout << "EMPLOYEE" << endl;

    Employee e1(101, 50000);
    e1.display();

    e1.setSalary(55000);

    cout << "\nAfter changing salary:" << endl;
    cout << "Salary = " << e1.getSalary() << endl;


    cout << "\n MANAGER " << endl;

    Manager m1(102, 70000, 10000);

    m1.displayManager();

    cout << "\nManager Bonus = "
         << m1.getBonus() << endl;

    m1.setBonus(15000);

    cout << "Updated Bonus = "
         << m1.getBonus() << endl;


    cout << "\nSALESMAN " << endl;

    Salesman s1(103, 40000, 5000);

    s1.displaySalesman();

    cout << "\nSalesman Commission = "
         << s1.getCommission() << endl;

    s1.setCommission(7500);

    cout << "Updated Commission = "
         << s1.getCommission() << endl;


    cout << "\n SALESMANAGER " << endl;

    SalesManager sm1(104, 80000, 20000, 10000);

    sm1.display();

    cout << "\nTesting getters:" << endl;
    cout << "ID         : " << sm1.getId() << endl;
    cout << "Salary     : " << sm1.getSalary() << endl;
    cout << "Bonus      : " << sm1.getBonus() << endl;
    cout << "Commission : " << sm1.getCommission() << endl;


    cout << "\nTesting setters:" << endl;

    sm1.setId(105);
    sm1.setSalary(85000);
    sm1.setBonus(25000);
    sm1.setCommission(12000);

    sm1.display();


    cout << "\n ACCEPT TEST" << endl;

    SalesManager sm2;

    sm2.accept();
    sm2.display();

    return 0;
}