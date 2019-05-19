// Program Name: Lab4
//
// Author: Jason Yoon
//
// Date: 7/22/2018
//
// IDE Used: Visual Microsoft
//

#ifndef LAB4_CUSTOMER
#define LAB4_CUSTOMER
using namespace std;

class Customer {

public:

	string lastname;
	string firstname;
	string id;


	Customer() {};
	~Customer() {};

	Customer (string last, string first,
				string iden) {
		lastname = last;
		firstname = first;
		id = iden;
	}


	void display() {
		cout << lastname << " " << firstname << " " << id;
	}

	// Converting the string to an int
	// Although it does not read the hyphen
	// in the ID
	int returnID() {
		stringstream returnID(id);
		int iden = 0;
		returnID >> iden;

		return iden;
	}
};


#endif
