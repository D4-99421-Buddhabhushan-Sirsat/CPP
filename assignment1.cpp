#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 1970;
}

void printDateOnConsole(struct Date* ptrDate) {
    cout << "Date: "
         << ptrDate->day << "/"
         << ptrDate->month << "/"
         << ptrDate->year << endl;
}

void acceptDateFromConsole(struct Date* ptrDate) {
    cout << "Enter day: ";
    cin >> ptrDate->day;

    cout << "Enter month: ";
    cin >> ptrDate->month;

    cout << "Enter year: ";
    cin >> ptrDate->year;
}

int main() {
    Date date;
    int choice;

    initDate(&date);

    do {
        cout << "\n--- Date Menu ---\n";
        cout << "1. Initialize Date\n";
        cout << "2. Accept Date\n";
        cout << "3. Print Date\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                initDate(&date);
                cout << "Date initialized successfully.\n";
                break;

            case 2:
                acceptDateFromConsole(&date);
                break;

            case 3:
                printDateOnConsole(&date);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
