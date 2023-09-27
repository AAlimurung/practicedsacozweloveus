//practice: singly linked list with base codes from f1 cm
#include<iostream>
#include"linklist4.h"
using namespace std;

int main(){
	SLL* list = new LinkList();
	char op;
	int n, pos;
	
	cout << "a - add" << endl;
	cout << "@ - addAt" << endl;
	cout << "r - remove" << endl; //not implemented yet
	cout << "R - removeAt" << endl;
	cout << "g - get position" << endl; //not implemented yet
	cout << "s - get sum" << endl;
	cout << "d - display" << endl;
	cout << endl;
	
	do{
		cout << "Enter operation: ";
		cin >> op;
		
		switch(op){
			case'a':
				cin >> n;
				list->add(n);
				break;
			case'@':
				cin >> n;
				cin >> pos;
				list->addAt(n, pos);
				break;
//			case'r':
			case'R':
				cin >> pos;
				list->removeAt(pos);
				break;
			case'g':
				cin >> pos;
				cout << list->get(pos) << " " << endl;
				break;
			case's':
				cout << "Sum of the list: " << list->getSum() << endl;
				break;
			case'd':
				list->display();
				break;			
		}
	}while(op != 'x');
	
	cout << "Thank you arrays." << endl;
	
	return 0;
}
