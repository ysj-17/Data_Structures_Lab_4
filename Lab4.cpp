// Program Name: Lab4
//
// Description:  
//  Using 3 methods for creating a Hash Table
//  Also using a dynamic array of Linked Lists 
//
// What's on your mind about this lab?
//  This Lab was a bit easier after the Radix Sort Lab
//	I understand the List data structure a lot better after this lab
//  
// Author: Jason Yoon
//
// Date: 7/22/2018
//
// IDE Used: Visual Microsoft
//


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "List.h"
#include "Hashtable.h"
using namespace std;

//int counter = 0;

void printCollisions(int chain, int linear, int quad);


int main() {

	string FILE_NAME = "Customer.csv";
	List<Customer> listCustomer;
	Hash<Customer> hashTable;
	string container;

	ifstream fileInput(FILE_NAME, ios::in);

	if (!fileInput.is_open()) {
		cout << "Error in Step 1: File not open" << endl;
	}
	
	// Get line count in file
	while (fileInput.good()) {
		getline(fileInput, container);
		counter++;
	}


	Customer* referenceCustomer = new Customer[counter];

	fileInput.close();
	fileInput.open(FILE_NAME);

	// Reading in the file into the ADT which also has a dynamic array
	for (int index = 0; index < counter; index++) {
		if (fileInput.good()) {
			getline(fileInput, container, ',');
			referenceCustomer[index].firstname = container;
			getline(fileInput, container, ',');
			referenceCustomer[index].lastname = container;
			getline(fileInput, container, '\n');
			referenceCustomer[index].id = container;
		}
		else {
			cout << "Error in Step 2: Not reading in data to list" << endl;
		}
	}

	// Calling the hashing functions
	int collisions_Chain = hashTable.hashChaining(referenceCustomer);
	int collisions_Linear = hashTable.hashLinear(referenceCustomer);
	int collisions_Quadratic = hashTable.hashQuadratic(referenceCustomer);

	// Fucntion to print which techniques yields the fewest collisions
	printCollisions(collisions_Chain, collisions_Linear, collisions_Quadratic);


	fileInput.close();
	delete[] referenceCustomer;


	cin.get();
	return 0;
}

void printCollisions(int chain, int linear, int quad){

	cout << "Number of collisions for Hash Chain is "
		<< chain << endl;
	cout << "Number of collisions for Hash Linear Probing is "
		<< linear << endl;
	cout << "Number of collisions for Hash Quadratic Probing is "
		<< quad << endl;

	if ((linear > chain) && (quad > chain)) {
		cout << "The Hash Chain method creates the least amount of collisions" << endl;
	}
	else if ((quad > linear) && (chain > linear)) {
		cout << "The Hash Linear Probing method creates the least amount of collisions" << endl;
	}
	else if ((chain > quad) && (linear > quad)) {
		cout << "The Hash Quadratic Probing method creates the least amount of collisions" << endl;
	}
	else if (linear == quad) {
		cout << "The Hash Linear Probing and Quadratic Probing have the same number"
			<< " of collisions at " << linear;
	}
	else if (chain == linear) {
		cout << "The Hash Chain and Linear Probing have the same number"
			<< " of collisions at " << chain;
	}
	else if (chain == quad) {
		cout << "The Hash Chain and Quadratic Pobing have the same number"
			<< " of collisions at " << chain;
	}

}