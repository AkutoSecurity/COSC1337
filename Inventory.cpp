//This program uses an Inventory class to hold a retail store's inventory data.
//NOTE: This program originally has three files: Main.cpp, Inventory.cpp, and Inventory.h. They are all included in this one file.

//Main.cpp File
#include "Inventory.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void getInfo(Inventory *, const int); //Function to collect user's inventory data
void displayInfo(const Inventory *, const int); //Function to display user's inventory data

int main() {
	const int NUM_ITEMS = 2; //Number of item types user can enter
	Inventory items[NUM_ITEMS]; //Stores the two item types

	cout << "COOL STORE WAREHOUSE";
	cout << endl << "=======================================================\n"
		<< "You will be asked to enter the information for 2 item types.\n\n";

	getInfo(items, NUM_ITEMS); //Calls getInfo function

	for (int i = 0; i < NUM_ITEMS; i++) { //Loops two times for the two item types
		items[i].setTotalCost(items[i].getCost());
	}

	displayInfo(items, NUM_ITEMS); //Calls displayInfo function


	return 0;
}

/********************************************************
*                        getInfo                        *
* Asks user for item number, quantity of item, and cost *
*                      of item.                         *
********************************************************/
void getInfo(Inventory *items, const int NUM_ITEMS) {
	int itemID = 0; //Will hold user-input item ID
	int itemQuantity = 0; //Will hold user-input quantity
	double itemCost = 0.0; //Will hold user-input item cost

	for (int i = 0; i < NUM_ITEMS; i++) { //Loops two times for two item types
		cout << "Please enter the item number: " << setw(5);
		cin >> itemID;
		cout << endl;

		while (!items[i].setItemNumber(itemID)) { //Input validation
			cout << "Please enter the item number: " << setw(5);
			cin >> itemID;
			cout << endl;
		}

		cout << "Please enter the quantity of this item: " << setw(4);
		cin >> itemQuantity;
		cout << endl;

		while (!items[i].setQuantity(itemQuantity)) { //Input validation
			cout << "Please enter the quantity of this item: " << setw(4);
			cin >> itemQuantity;
			cout << endl;
		}

		cout << "Please enter the cost of the item: " << setw(4);
		cin >> itemCost;
		cout << endl;

		while (!items[i].setCost(itemCost)) { //Input validation
			cout << "Please enter the cost of this item: " << setw(4);
			cin >> itemCost;
			cout << endl;
		}

		cout << "**********************************************" << endl;
	}
}

/*********************************************************
*                    displayItems                        *
* Displays information about the items                   *
*********************************************************/
void displayInfo(const Inventory *items, const int NUM_ITEMS) {
	cout << endl << "COOL STORE WAREHOUSE" << "\n\n" << setw(5) << "Item ID "
		<< setw(19) << "Item Quantity "
		<< setw(13) << "Cost of Item "
		<< setw(20) << "Total Cost\n";
	cout << "==========================================================\n";

	for (int i = 0; i < NUM_ITEMS; i++) { //Repeats two times for two item types and creates organized table of data
			cout << setw(7) << items[i].getItemNumber()
				<< setw(19) << items[i].getQuantity();
			cout << showpoint << fixed << setprecision(2);
			cout << setw(13) << items[i].getCost()
				<< setw(19) << items[i].getTotalCost() << "\n";
	}
}


//Inventory.cpp File
#include "Inventory.h"
#include <string>
#include <iostream>
using namespace std;

/***************************************************
*             Inventory::setItemNumber:            *
* Sets value of its member variable itemNumber     *
***************************************************/
bool Inventory::setItemNumber(int newItemNumber) {
	if (newItemNumber > 0) { //If the item number is positive, it gets passed into the item number variable
		itemNumber = newItemNumber;
		return true;
	}
	else { //If the item number is negative, it is invalidated
		cout << "You have entered an invalid item ID.\n\n";
		return false;
	}
}

/****************************************************
*               Inventory::setQuantity              *
* Sets value of its member variable quantity        *
****************************************************/
bool Inventory::setQuantity(int newQuantity) {
	if (newQuantity > 0) { //If the quantity is positive, it gets passed into the quantity variable
		quantity = newQuantity;
		return true;
	}
	else { //If the quantity is negative, it is invalidated
		cout << "Item quantity cannot be below zero.\n\n";
		return false;
	}
}

/****************************************************
*                 Inventory::setCost                *
* Sets value of its member variable cost            *
****************************************************/
bool Inventory::setCost(double newCost) {
	if (newCost > 0) { //If the cost is positive, it gets passed into the cost variable
		cost = newCost;
		return true;
	}
	else { //If the cost is negative, it is invalidated
		cout << "Item cost cannot be below zero.\n\n";
		return false;
	}
}

/****************************************************
*             Inventory::setTotalCost               *
* Sets value of its member totalCost.               *
* Total cost is found by multiplying quantity and   *
*                      cost.                        *
****************************************************/
void Inventory::setTotalCost(double newCost) {
	totalCost = quantity * newCost;
}


//Inventory.h File
class Inventory {
private:
	int itemNumber; //The item number
	int quantity; //The number of available items
	double cost; //The per-unit price of the item
	double totalCost; //The total cost of the items

public:
	Inventory() { //Default constructor
		itemNumber = 0;
		quantity = 0;
		cost = 0.0;
		totalCost = 0.0;
	}

	Inventory(int newItemNumber, int newQuantity, double newCost) { //Overflow constructor
		itemNumber = newItemNumber;
		quantity = newQuantity;
		cost = newCost;
	}

	//Mutators
	bool setItemNumber(int newItemNumber); //Validates item number
	bool setQuantity(int newQuantity); //Validates quantity
	bool setCost(double newCost); //Validates cost
	void setTotalCost(double newCost); //Validates total cost

	//Accessors
	int getItemNumber() const { //Gets item number
		return itemNumber;
	}

	int getQuantity() const { //Gets quantity of item
		return quantity;
	}

	double getCost() const { //Gets cost of item
		return cost;
	}

	double getTotalCost() const { //Gets total cost of item
		return totalCost;
	}

};
