#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next = NULL; //make next as NULL kay dili ma-ponit ang non-pointer to an int
};

//that person's so pretty
int main(){
	int s; //size
	cout << "Enter size: ";
	cin >> s;
	
	Node* newton = NULL; //newton is a node TT
	Node* head = NULL;
	Node* tail = NULL;
	
	for(int i=0; i<s; i++){
		Node* newton = new Node;
		cout << "Enter data " << i+1 << ": ";
		cin >> newton->data;
		newton->next = NULL;
		
		if(head == NULL){
			head = newton;
			tail = newton;
		}else{
			tail->next = newton;
			tail = newton;
		}
	}
	
	Node* p = NULL;
	p = head;
	
	while(p!=NULL){
		cout << p->data;
		if(p->next!=NULL){
			cout << " -> ";
		}else{
			cout << " -> NULL";
		}
		p = p->next;
	}
	
	return 0;
}
