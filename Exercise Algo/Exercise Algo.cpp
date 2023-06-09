#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** seis, Node** wisnu);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int rollNumber;
	string name;
	cout << "\nMasukan Angka: ";
	cin >> rollNumber;
	cout << "\nMasukan Nama: ";
	cin >> name;

	Node* currentNode = new Node;
	currentNode->rollNumber;
	currentNode->name;

	if (LAST == NULL || rollNumber <= LAST->rollNumber) {
		if ((LAST != NULL) && (rollNumber == LAST->rollNumber)) {
			cout << "\nDuplicate not allowed\n";
			return;
		}
		currentNode->next = LAST;
		LAST = currentNode;
		return;
	}
	Node* seis, * wisnu;

	wisnu = LAST;
	seis = LAST;

	while ((wisnu != NULL) && (rollNumber >= wisnu->rollNumber)) {
		if (rollNumber == wisnu->rollNumber) {
			cout << "\nDuplicate not allowed\n";
			return;
		}
		seis = wisnu;
		wisnu = wisnu->next;
	}
	currentNode->next = wisnu;
	seis->next = currentNode;
}
bool CircularLinkedList::search(int rollno, Node** seis, Node** wisnu) {
	*seis = LAST->next;
	*wisnu = LAST->next;
	while (*wisnu != LAST) {
		if (rollno == (*wisnu)->rollNumber) {
			return true;
		}
		*seis = *wisnu;
		*wisnu = (*wisnu)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollNumber) { 
	Node* wisnu, * seis;
	if (search(rollNumber, &seis, &wisnu) == false)
		return false;
	seis->next = wisnu->next;
	if (wisnu == LAST)
		LAST = LAST->next;

	delete wisnu;
	return true;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	int rollNumber;

	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
					break;
			case '2': {
				if (obj.listEmpty())
				{
					cout << endl << "List Kosong" << endl;
					break;
				}
				cout << endl << "\nMasukan no mahasiswa yang akan dihapus : ";
				cin >> rollNumber;
				if (obj.delNode(rollNumber) == false)
					cout << "Data not found" << endl;
				else
					cout << endl << "data: " << rollNumber << "succes deleted" << endl;
			}
					break;

			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}