#include<iostream>
#include"dlinklist.h"
using namespace std;

int main(){
	DLL* list = new dlinklist();
	char ch;
	int n, pos, a, b;
	
	cout << "h = add head" << endl;
	cout << "t = add tail" << endl;
	cout << "@ = add at" << endl;
	cout << "H = remove head" << endl;
	cout << "L = remove tail" << endl;
	cout << "r = remove" << endl;
	cout << "R = remove at" << endl;
//	cout << "g = get" << endl;
//	cout << "n = retain" << endl;
	cout << "c = corner" << endl;
//	cout << "v = reverse linked list" << endl;
	cout << "p = print" << endl;
	cout << endl;
	
	do{
		cout << "Op: ";
		cin >> ch;
		
		switch(ch){
			case 'h':
				cin >> n;
				list->addH(n);
				break;
			case 't':
				cin >> n;
				list->addT(n);
				break;
			case '@':
				cin >> n;
				cin >> pos;
				list->addAt(n, pos);
				break;
			case 'H':
				list->removeH();
				break;		
			case 'T':
				list->removeT();
				break;
			case 'r':
				cin >> n;
				list->remove(n);
				break;
			case 'R':
				cin >> pos;
				list->removeAt(pos);
				break;
			case 'c':
				cin >> a >> b;
				cout << "Removed " << list->corner(a, b) << " elements" << endl;
				break;
			case 'p':
				cout << endl;
				list->print();
				break;
		}
		
	}while(ch != 'x');
	
	return 0;
}
