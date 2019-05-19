// Program Name: Lab4
//
// Author: Jason Yoon
//
// Date: 7/22/2018
//
// IDE Used: Visual Microsoft
//

#ifndef LAB4_HASH
#define LAB4_HASH
int counter = 0;

//Chose the Chaining, Linear Probing, and Quadratic Probing methods



template <class T>
class Hash : public List<T> {
public: 
	Hash() {};

	int hashChaining(Customer object[]);
	int hashLinear(Customer object[]);
	int hashQuadratic(Customer object[]);
	
};


template <class T>
int Hash<T>::hashChaining(Customer object[]) {

	int buckSize = 10;
	bool done = false;
	int collisions = 0;
	
	// Do-while loop controls the resizing of dynamic array
	do {

		List<T>* bucketArray = new List<T>[buckSize];

		// Moving contents to container
		for (int index = 0; index < counter - 1; index++) {
			int container = object[index].returnID();
			bucketArray[container % buckSize].add(object[index]);
		}


		if (buckSize < counter) {
			buckSize = buckSize * 2;
			delete [] bucketArray; // deletion of previous container
			done = false;
		}
		else done = true;

		// Counting the collisions here
		if (done == true) {
			for (int colliCounter = 0; colliCounter < buckSize; colliCounter++) {
				if (bucketArray[colliCounter].sizeOfList() != 1) // Done to avoid counting 1 node only
					collisions += bucketArray[colliCounter].sizeOfList();
			}
		}

	} while (!done);

	return collisions;
}

template <class T>
int Hash<T>::hashLinear(Customer object[]) {
	
	int buckSize = 10;
	bool done = false;
	int collisions = 0;
	int bucketsProbed = 0;

	// Do-while loop controls the resizing of dynamic array
	do {

		List<T>* bucketArray = new List<T>[buckSize];

		// Moving contents to container
		for (int index = 0; index < counter - 1; index++) {
			int container = object[index].returnID();
			while (bucketsProbed < counter - 1) {
				bucketsProbed++;
				if (bucketArray[container % buckSize].isEmpty() == true)
					bucketArray[container % buckSize].add(object[index]);
			}
		}

		if (buckSize < counter) {
			buckSize = buckSize * 2;
			delete[] bucketArray; // deletion of previous container
			bucketsProbed = 0;
			done = false;
		}

		else done = true;

		if (done == true) {
			for (int colliCounter = 0; colliCounter < buckSize; colliCounter++) {
				if (bucketArray[colliCounter].sizeOfList() != 1)
					collisions += bucketArray[colliCounter].sizeOfList();
			}
		}

	} while (!done);

	return collisions;
}


template <class T>
int Hash<T>::hashQuadratic(Customer object[]) {

	int buckSize = 10;
	bool done = false;
	int collisions = 0;
	int bucketsProbed = 0;
	int insert = 0;

	// Do-while loop controls the resizing of dynamic array
	do {

		List<T>* bucketArray = new List<T>[buckSize];

		// Moving contents to container
		for (int index = 0; index < counter - 1; index++) {
			int container = object[index].returnID();
			int bucket = container % buckSize;
			while (bucketsProbed < counter - 1) {
				if (bucketArray[bucket].isEmpty() == true)
					bucketArray[bucket].add(object[index]);

				// Increment index and recompute bucket index
				// Chose "1" for c1 and c2
				insert = insert + 1;
				bucket = (container + (1 * insert) + (1 * insert) * insert) % buckSize;

				bucketsProbed++;


			}
		}

		if (buckSize < counter) {
			buckSize = buckSize * 2;
			delete[] bucketArray; // deletion of previous container
			bucketsProbed = 0;
			done = false;
		}

		else done = true;

		if (done == true) {
			for (int colliCounter = 0; colliCounter < buckSize; colliCounter++) {
				if (bucketArray[colliCounter].sizeOfList() != 1)
					collisions += bucketArray[colliCounter].sizeOfList();
			}
		}

	} while (!done);

	return collisions;
}




#endif