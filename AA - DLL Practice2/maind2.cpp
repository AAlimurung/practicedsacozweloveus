#include<iostream>
using namespace std;
//add head and tail only.
struct Node{
	int value;
	Node* next;
	Node* prev;
};

int main(){
	char set;
//	int num;
	
	Node* head = NULL;
	Node* tail = NULL;
	Node* newton = NULL;
	
	do{
		cout << "Op: ";
		cin >> set;
		
		switch(set){
			case 'a':
				newton = new Node;
				
				cin >> newton->value;
				newton->next = NULL;
				
				if(!tail) //if walay tail
					head = tail = newton; //set newton as head and tail
				else{
					tail->next = newton; //
					newton->prev = tail; //
					tail = newton;
				}
				break;
			case 'h':
				newton = new Node;
				cin >> newton->value;
				
				if(!head)
					tail = head = newton;
				else{
					head->prev = newton;
					newton->next = head;
					head = newton;
				}
				break;
			case 'p':
				Node* compass = head; //compass = pointer to head
				while(compass != NULL){
					cout << compass->value;
					
					if(compass->next != NULL)
						cout << " <-> ";
					else
						cout << " <-> NULL";
						
					compass = compass->next;
				}
				cout << endl;
				break;
		}
	}while(set != 'x');
	
	cout << "thank you singly lists" << endl;
	return 0;
}
