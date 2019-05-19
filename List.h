// Program Name: Lab4
//
// Author: Jason Yoon
//
// Date: 7/22/2018
//
// IDE Used: Visual Microsoft
//


#ifndef LAB4_LIST
#define LAB4_LIST
#include <string>


template <class T>
class Node
{
public:
	T  item;
	Node *prev;
	Node *next;
	Node *head;
	Node *tail;
};

int itemCountList = 0;

template <class T> class ListInterface : public Node<T>
{
public:

	virtual bool isEmpty() { return true; }
	virtual bool add(T newEntry) { return true; }
	virtual bool remove(T anEntry) { return true; }
	virtual void clear() { cout << "Error in ListInterface Class"; }
	virtual bool search(T anEntry) { return true; }
	virtual bool displayList() { return true; }
	virtual void sortingList() {}
};



template <class T> class List : public ListInterface<T>
{
private:
	//using Node<T>::head;
	//using Node<T>::tail;


public:
	using Node<T>::head;
	using Node<T>::tail;
	List() { head = nullptr; tail = nullptr; }

	int sizeOfList();


	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else { return false; }
	}


	bool add(T newEntry) {
		Node<T> *newNode = new Node<T>;
		newNode->item = newEntry;
		newNode->head = NULL;
		newNode->tail = NULL;

		if (isEmpty() == true) {
			head = newNode;
			tail = newNode;
			itemCountList++;
		}
		else {
			newNode->next = tail;
			tail->prev = newNode;
			tail = newNode;
			tail->prev = NULL;
			itemCountList++;
		}

		return true;
	}

	
};



template<class T>
int List<T>::sizeOfList() {
	int counter = 0;

	Node<T> *rover = head;
	if (isEmpty() == true) {
		return 0;
	}
	else {
		while (rover != NULL) 
		{
			rover = rover->prev;
			counter++;
		}

		return counter;
	}
}


#endif