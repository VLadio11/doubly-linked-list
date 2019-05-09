//put your implementation of LinkedList class here
#include "list.h"

LinkedList::LinkedList(){

}

bool LinkedList::addAtBeginning(int val)
{
	Node * newNode;
	newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;

	if (!head) {
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = NULL;
		head = newNode;
	}
	return true;
}

bool LinkedList::remove(int val)
{
	Node * current, *before, *after;
	current = new Node;
	current = head;
	for (current = head; current; current = current->next) {
		if ((current->prev == NULL) && (current->data == val)) {
			head = head->next;
			head->prev = NULL;
			current->next = NULL;
			delete current;
			return true;
		}
		else if ((current->next != NULL) && (current->prev != NULL) && (current->data == val)) {
			before = new Node;
			after = new Node;
			before = current->prev;
			after = current->next;
			before->next = after;
			after->prev = before;
			delete current;
			return true;
		}
	}
	current = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete current;
	return true;
}

void LinkedList::printForward() const
{
	Node * current;
	current = new Node;
	cout << endl <<"Printed Forwards: ";
	for (current = head; current; current = current->next) {
		cout << " " <<current->data;
	}
}
void LinkedList::printBackward() const
{
	Node * current;
	current = new Node;
	cout << endl <<"Printed Backwards: ";
	for (current = tail; current; current = current->prev) {
		cout << " " <<current->data;
	}
}




