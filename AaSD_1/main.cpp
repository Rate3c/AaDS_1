//Nesterov Evgeny 0301

#pragma once

#include "UnorderedList.h"

using namespace std;


int main() {
	UnorderedList list;

	list.push_back(2);
	list.push_back(3);
	cout << "1. add to the end of the list: " << list << endl;

	list.push_front(1);
	cout << "2. add to the top of the list: " << list << endl;

	list.insert(2, 3554);
	cout << "3. insert to list: " << list << endl;

	list.remove(2);
	cout << "4. delete a node: " << list << endl;

	list.set(0, 11);
	cout << "5. replace a node: " << list << endl;

	list.pop_back();
	cout << "6. remove node from the end of the list: " << list << endl;

	list.pop_front();
	cout << "7. remove node from the top of the list: " << list << endl;

	cout << "8. node with index 0: " << list.at(0) << endl;;

	cout << "9. size of the list: " << list.get_size() << endl;

	list.clear();
	cout << "10. clear list: " << list << endl;

	UnorderedList list_2;
	list_2.push_back(1);
	list_2.push_back(3);
	list_2.push_back(4);
	list_2.push_back(5);
	list_2.push_back(9);
	list_2.push_back(14);
	cout << "New 2nd list: " << list_2 << endl;

	UnorderedList list_3;
	list_3.push_back(4);
	list_3.push_back(5);
	list_3.push_back(9);
	cout << "New 3rd list: " << list_3 << endl;
	cout << "Contains or not list_2 sublist list_3: " << list_2.contains(list_3) << endl;

	return 0;
}