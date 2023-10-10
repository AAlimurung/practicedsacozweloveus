#include<iostream>
#include"doubly.h"
using namespace std;

int main(){
	int num, pos;
	char ch;
	dll* list = new doubly();
	
	cout << "h = add Head" << endl;
	cout << "t = add Tail" << endl;
	cout << "@ = add at position" << endl;
	cout << "d = remove head" << endl;
	cout << "l = remove tail" << endl;
	cout << "r = remove at position" << endl;
	cout << "R = remove All" << endl;
	cout << "g = get position" << endl;
	cout << "y = reverse list" << endl;
	cout << "p = print normal" << endl;
	cout << "v = print reverse" << endl;
//	cout << endl;
	
	do{
		cout << "Choice: ";
		cin >> ch;
		
		switch(ch){
			case 'h':
				cin >> num;
				list->addH(num);
				break;
			case 't':
				cin >> num;
				list->addT(num);
				break;
			case 'p':
				list->printNorm();
				break;
			case 'v':
				list->printRev();
				break;
			default:
				cout << "You mistyped. Try again" << endl;
		}
	}while(ch != 'x');
	
	cout << "Thank you singly linked lists" << endl;
	return 0;
}
