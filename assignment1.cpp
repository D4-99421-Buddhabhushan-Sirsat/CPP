// Q1)
/*
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 1970;
}

void printDateOnConsole(struct Date *ptrDate) {
    printf("Date: %d/%d/%d\n",
           ptrDate->day,
           ptrDate->month,
           ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate) {
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);

    printf("Enter month: ");
    scanf("%d", &ptrDate->month);

    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}

int main() {
    struct Date date;
    int choice;

    initDate(&date);

    do {
        printf("\n--- Date Menu ---\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date\n");
        printf("3. Print Date\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initDate(&date);
                printf("Date initialized successfully.\n");
                break;

            case 2:
                acceptDateFromConsole(&date);
                break;

            case 3:
                printDateOnConsole(&date);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
*/

// Q2)

#include <iostream>

using namespace std;

// Date implemented using a structure.
struct DateStruct {
	int day;
	int month;
	int year;
};

void initDate(DateStruct &date) {
	date.day = 1;
	date.month = 1;
	date.year = 1970;
}

void printDateOnConsole(const DateStruct &date) {
	cout << "Date: " << date.day << "/" << date.month << "/" << date.year << '\n';
}

void acceptDateFromConsole(DateStruct &date) {
	cout << "Enter day: ";
	cin >> date.day;
	cout << "Enter month: ";
	cin >> date.month;
	cout << "Enter year: ";
	cin >> date.year;
}

bool isLeapYear(const DateStruct &date) {
	return (date.year % 400 == 0) ||
		   (date.year % 4 == 0 && date.year % 100 != 0);
}

// Date implemented using a class.
class Date {
private:
	int day;
	int month;
	int year;

public:
	void initDate() {
		day = 1;
		month = 1;
		year = 1970;
	}

	void printDateOnConsole() const {
		cout << "Date: " << day << "/" << month << "/" << year << '\n';
	}

	void acceptDateFromConsole() {
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
	}

	bool isLeapYear() const {
		return (year % 400 == 0) ||
			   (year % 4 == 0 && year % 100 != 0);
	}
};

int main() {
	DateStruct structureDate;
	Date classDate;
	int choice;

	initDate(structureDate);
	classDate.initDate();

	do {
		cout << "\n--- Date Menu ---\n"
			 << "1. Initialize both dates\n"
			 << "2. Accept structure date\n"
			 << "3. Print structure date\n"
			 << "4. Check structure date leap year\n"
			 << "5. Accept class date\n"
			 << "6. Print class date\n"
			 << "7. Check class date leap year\n"
			 << "0. Exit\n"
			 << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				initDate(structureDate);
				classDate.initDate();
				cout << "Both dates initialized successfully.\n";
				break;
			case 2:
				acceptDateFromConsole(structureDate);
				break;
			case 3:
				printDateOnConsole(structureDate);
				break;
			case 4:
				cout << (isLeapYear(structureDate) ? "Leap year\n" : "Not a leap year\n");
				break;
			case 5:
				classDate.acceptDateFromConsole();
				break;
			case 6:
				classDate.printDateOnConsole();
				break;
			case 7:
				cout << (classDate.isLeapYear() ? "Leap year\n" : "Not a leap year\n");
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
