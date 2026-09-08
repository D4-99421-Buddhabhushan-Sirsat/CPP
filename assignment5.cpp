#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {}

    Date(int day, int month, int year)
        : day(day), month(month), year(year) {}

    void setDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void display() const
    {
        cout << day << "/" << month << "/" << year;
    }
};

class Person
{
private:
    string name;
    string address;
    Date birthdate;

public:
    Person(const string& name, const string& address, const Date& birthdate)
        : name(name), address(address), birthdate(birthdate) {}

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.display();
        cout << endl;
    }
};

class Student
{
private:
    int id;
    float marks;
    string course;
    Date joiningDate;
    Date endDate;

public:
    Student(int id, float marks, const string& course,
            const Date& joiningDate, const Date& endDate)
        : id(id), marks(marks), course(course),
          joiningDate(joiningDate), endDate(endDate) {}

    void display() const
    {
        cout << "Student ID: " << id << endl;
        cout << "Marks: " << marks << endl;
        cout << "Course: " << course << endl;
        cout << "Joining Date: ";
        joiningDate.display();
        cout << endl;
        cout << "End Date: ";
        endDate.display();
        cout << endl;
    }
};

int main()
{
    Date birthdate(15, 8, 2002);
    Person person("Rahul", "Pune", birthdate);

    Date joiningDate(1, 7, 2022);
    Date endDate(30, 6, 2025);
    Student student(101, 85.5f, "Computer Science", joiningDate, endDate);

    cout << "Person Details" << endl;
    person.display();

    cout << "\nStudent Details" << endl;
    student.display();

    cout << "\nUpdating a date:" << endl;
    birthdate.setDate(20, 8, 2002);
    cout << "Updated date: ";
    birthdate.display();
    cout << endl;

    Date p2BirthDate(20, 4, 2004);
    Person p2("bhushan", "Silicon Valley", p2BirthDate);

    cout<< "\nPerson 2 Details" << endl;
    p2.display();
    cout<<endl;

    return 0;
}
