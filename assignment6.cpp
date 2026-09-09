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