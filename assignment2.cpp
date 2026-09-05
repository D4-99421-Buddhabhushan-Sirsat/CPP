// Q1) Menu-driven volume calculation using constructor overloading.

// #include <iostream>

// using namespace std;

// class Box {
// private:
// 	int length;
// 	int breadth;
// 	int height;

// public:
// 	Box() : length(1), breadth(1), height(1) {}

// 	Box(int side) : length(side), breadth(side), height(side) {}

// 	Box(int boxLength, int boxBreadth, int boxHeight){
//         this->length = boxLength;
//         this->breadth = boxBreadth;
//         this->height = boxHeight;
//     }

//     // Box(int boxLength, int boxBreadth, int boxHeight) : length(boxLength), breadth(boxBreadth), height(boxHeight)
//     // {

//     // }

// 	int calculateVolume() {
// 		return length * breadth * height;
// 	}
// };

// int main() {
// 	int choice;

// 	do {
// 		cout << "\n--- Box Volume Menu ---\n"
// 			 << "1. Calculate Volume with default values\n"
// 			 << "2. Calculate Volume with length, breadth and height with same value\n"
// 			 << "3. Calculate Volume with different length, breadth and height values\n"
// 			 << "0. Exit\n"
// 			 << "Enter your choice: ";
// 		cin >> choice;

// 		switch (choice) {
// 			case 1: {
// 				Box box;
// 				cout << "Volume: " << box.calculateVolume() << '\n';
// 				break;
// 			}

// 			case 2: {
// 				int side;
// 				cout << "Enter the common value: ";
// 				cin >> side;
// 				Box box(side);
// 				cout << "Volume: " << box.calculateVolume() << '\n';
// 				break;
// 			}

// 			case 3: {
// 				int length;
// 				int breadth;
// 				int height;
// 				cout << "Enter length, breadth and height: ";
// 				cin >> length >> breadth >> height;
// 				Box box(length, breadth, height);
// 				cout << "Volume: " << box.calculateVolume() << '\n';
// 				break;
// 			}

// 			case 0:
// 				cout << "Exiting program.\n";
// 				break;

// 			default:
// 				cout << "Invalid choice.\n";
// 		}
// 	} while (choice != 0);

// 	return 0;
// }



// Q2) Tollbooth model.

#include <iostream>

using namespace std;

class tollbooth {
private:
	unsigned int totalCars;
	double totalCash;
	unsigned int payingCars;
	unsigned int nonPayingCars;

public:
	tollbooth()
		: totalCars(0), totalCash(0.0), payingCars(0), nonPayingCars(0) {}

	void payingCar() {
		++totalCars;
		++payingCars;
		totalCash += 0.50;
	}

	void nopayCar() {
		++totalCars;
		++nonPayingCars;
	}

	void printOnConsole() const {
		cout << "Total cars: " << totalCars << '\n'
			 << "Total cash collected: INR " << totalCash << '\n'
			 << "Paying cars: " << payingCars << '\n'
			 << "Non-paying cars: " << nonPayingCars << '\n';
	}
};

int main() {
	tollbooth booth;

	booth.payingCar();
	booth.payingCar();
	booth.nopayCar();
	booth.payingCar();

	booth.printOnConsole();
	return 0;
}