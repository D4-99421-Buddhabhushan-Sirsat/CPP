#include<iostream>
using namespace std;

class Employee
{
private:
    int id;
    double salary;  
public:
    Employee(){
        id = 0;
        salary = 0;
    }
    Employee(int id, double salary){
        this->id = id;
        this->salary = salary;
    }
    void setId(int id){
        this->id = id;
    }
    int getId(){
        return id;
    }
    void setSalary(double salary){
        this->salary = salary;
    }
    double getSalary(){
        return salary;  
    }
    virtual void accept(){
        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Salary: ";
        cin >> salary;
    }
    virtual void display(){
        cout << "ID     : " << id << endl;      
        cout<<"Salary   : "<<salary<<endl;
    }

    virtual ~Employee() {}
};   

class Manager : virtual public Employee{
private:
    double bonus;
public:
    Manager(){
        bonus = 0;
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary){
        this->bonus = bonus;
    }
    void setBonus(double bonus){
        this->bonus = bonus;
    }
    double getBonus(){
        return bonus;   
    }

    void accept() override{
        Employee::accept();
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void acceptManager(){
        accept();
    }

    void display () override{
        Employee::display();
        displayManager();
    }

    void displayManager(){
        cout << "Bonus  : " << bonus << endl;
        cout<<"Designation : Manager"<<endl;
    }
};    

class Salesman : virtual public Employee{
private:
    double commission;
public:
    Salesman(){
        commission = 0;
    }

    Salesman(int id, double salary, double commission) : Employee(id, salary){
        this->commission = commission;
    }

    void setCommission(double commission){
        this->commission = commission;
    }

   double getCommission(){
        return this->commission;
    }

    void accept() override{
        Employee::accept();
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void acceptSalesman(){
        accept();
    }

    void display()override{
        Employee::display();
        displaySalesman();
    }

    void displaySalesman(){
        cout << "Commission : " << commission << endl;
        cout<<"Designation : Salesman"<<endl;
    }
};

class salesmanager : public Manager, public Salesman{
public:
    salesmanager(){

    }

    salesmanager(int id, double salary, double bonus, double commission)
        : Employee(id, salary),
          Manager(id, salary, bonus),
          Salesman(id, salary, commission)
    {
    }
    void accept() override {
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

    void display() override
    {
        Employee::display();
        cout << "Bonus      : " << Manager::getBonus() << endl;
        cout << "Commission : " << Salesman::getCommission() << endl;
        cout<<"Designation : Sales Manager"<<endl;
    }
};

int main(){

    Employee *eptr[1001];
    int totalCount = 0;
    int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;
    int choice;

    do{
       cout << "\n1. Add manager" << endl;
       cout << "2. Add salesman" << endl;
       cout << "3. Add salesmanager" << endl;
       cout << "4. Display all managers" << endl;
       cout << "5. Display all salesmen" << endl;
       cout << "6. Display all salesmanagers" << endl;
       cout << "7. Display the count of all employees with respect to designation" << endl;
       cout << "8. Exit" << endl;
       cout << "Enter your choice: ";
       cin >> choice;

       switch(choice){

           case 1: {
               eptr[totalCount] = new Manager();
               eptr[totalCount]->accept();
               totalCount++;
               managerCount++;
               cout << "Manager added successfully.\n";
               break;
           }

           case 2: {
               eptr[totalCount] = new Salesman();
               eptr[totalCount]->accept();
               totalCount++;
               salesmanCount++;
               cout << "Salesman added successfully.\n";
               break;
           }

           case 3: {
               eptr[totalCount] = new salesmanager();
               eptr[totalCount]->accept();
               totalCount++;
               salesManagerCount++;
               cout << "SalesManager added successfully.\n";
               break;
           }

           case 4: {
               cout << "\n--- All Managers ---\n";
               bool found = false;
               for(int i = 0; i < totalCount; i++){
                   // dynamic_cast returns non-null only if the object is really a Manager
                   // (and not a salesmanager, since we want plain Managers only)
                   if(dynamic_cast<salesmanager*>(eptr[i]) == nullptr &&
                      dynamic_cast<Manager*>(eptr[i]) != nullptr){
                       eptr[i]->display();
                       cout << "-----------------------\n";
                       found = true;
                   }
               }
               if(!found) cout << "No Managers found.\n";
               break;
           }

           case 5: {
               cout << "\n--- All Salesmen ---\n";
               bool found = false;
               for(int i = 0; i < totalCount; i++){
                   if(dynamic_cast<salesmanager*>(eptr[i]) == nullptr &&
                      dynamic_cast<Salesman*>(eptr[i]) != nullptr){
                       eptr[i]->display();
                       cout << "-----------------------\n";
                       found = true;
                   }
               }
               if(!found) cout << "No Salesmen found.\n";
               break;
           }

           case 6: {
               cout << "\n--- All SalesManagers ---\n";
               bool found = false;
               for(int i = 0; i < totalCount; i++){
                   if(dynamic_cast<salesmanager*>(eptr[i]) != nullptr){
                       eptr[i]->display();
                       cout << "-----------------------\n";
                       found = true;
                   }
               }
               if(!found) cout << "No SalesManagers found.\n";
               break;
           }

           case 7: {
               cout << "\n--- Employee Count by Designation ---\n";
               cout << "Managers      : " << managerCount << endl;
               cout << "Salesmen      : " << salesmanCount << endl;
               cout << "SalesManagers : " << salesManagerCount << endl;
               cout << "Total Employees: " << totalCount << endl;
               break;
           }

           case 8: {
               cout << "Exiting program.\n";
               break;
           }

           default: {
               cout << "Invalid choice. Try again.\n";
           }
       }

    }while(choice != 8);

    // free allocated memory
    for(int i = 0; i < totalCount; i++){
        delete eptr[i];
    }

    return 0;
}