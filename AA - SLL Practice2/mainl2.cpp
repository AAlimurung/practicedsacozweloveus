#include<iostream>
#include"linklist2.h"
using namespace std;

int main(){
	LL* l = new LinkList();
	char set;
	int n, pos;
	
	cout << "a - add" << endl;
	cout << "@ - addAt" << endl;
	cout << "r - removeAt" << endl;
	cout << "d - display" << endl;
	cout << "s - sum" << endl;
	cout << endl;
	
	do{
		cout << "Enter operation: ";
		cin >> set;
		
		switch(set){
			case 'a':
				cin >> n;
				l->plus(n);
				break;
			case '@':
				cin >> n;
				cin >> pos;
				l->addAt(n, pos);
				break;
			case 'r':
				cin >> pos;
				l->removeAt(pos);
				break;
			case 'd':
				l->display();
				break;
			case 's': 
				cout << "Sum of the list: " << l->getSum() << endl;
				break;
		}
	}while(set!='x');
	
	cout << "thank you arrays." << endl;
	
	return 0;
}

