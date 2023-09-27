#include<iostream>
#include"list4.h"
using namespace std;

//ako gi-declare ang struct here for easier access sa mga variables;
struct Node{ //elements for the linked list;
	int data; //elem ni sir;
	Node* next = NULL; //Node* can already be used in here because
						//you declared the struct naman;
						
};

class LinkList : public SLL{
	//private ang head and tail for this version
//	int size; //pakyu size
	Node* head;
	Node* tail;
	
	public:
			Link(){
				//declaring head, tail, and size
				head = NULL;
				tail = NULL;
//			    size = 0;
			}
			
//			void addLast(int data){
//			}

			void add(int data){
				if(head == NULL){ 
					//used to input the first element in the list
					Node* node1 = new Node; //instead of malloc, kay nag new variable ko. Meaning, it also allocated memory
					node1->data = data; //node->data becomes the input you entered
					node1->next = NULL; // set the pointer to the next as NULL
					head = node1; //update head
				}else if(tail == NULL){ 
					//for the next elements
					Node* node1 = new Node; 
					node1->data = data;
					node1->next = NULL;
					head->next = node1; //pointer to the next points back to the head of the node
					tail = node1; //update the tail as node1
				}else{ //sometimes, i wanna delete this code and place it somewhere else but wtf, i have no idea where
					Node* node1 = new Node;
					node1->data = data;
					node1->next = NULL;
					tail->next = node1; //node becomes the next pointer of the tail
					tail = node1; //update tail as node1
				}
				
				return;
			}
			
//			void remove(int pos){
//			}

			void removeAt(int pos){
				if(head == NULL || pos <= 0){ //if head == NULL, this mean na walay sulod ang list, so invalid siya
				// also, if pos <= 0, it's an invalid position kay lists start with index 1
					cout << "Way sulod ang list." << endl;
					return;
				}else if(pos == 1){ //if pos == 1, 
					Node* nodetemp = head; //declare a temp para i-store ang head
					head = head->next; //head is then transfered sa next para mahimo as head
					delete nodetemp; //deallocate ang head coz it was the old head para no memory leak
					return; 
					//head = head->next means na dli naka mobalik sa original address ni head
				}
				
				Node* curr = head;
				int count = 1;
				
				while(curr!=NULL && count < pos-1){
					curr = curr->next;
					count++;
				}
				
				Node* nodetemp = curr->next;
				curr->next = nodetemp->next;
				
				if(nodetemp->next == NULL){
					curr->next = NULL;
					tail = curr;
				}
				//WHAHAHAHHAHA kapoya type comments oi
				delete nodetemp;
				return;
			}
			
			void addAt(int data, int pos){
				if(head == NULL || pos <= 0){
					cout << "Walay sulod ang list lagi." << endl;
					return;
				}else if(pos == 1){
					Node* nodetemp = new Node;
					nodetemp->data = data;
					nodetemp->next = head;
					head = nodetemp;
					return;
				}
				
				Node* curr = new Node;
				int count = 1;
				
				while(curr!=NULL && count < pos-1){
					curr = curr->next;
					count++;
				}
				
				Node* nodetemp = new Node;
				nodetemp->data = data;
				nodetemp->next = curr->next;
				
				if(curr->next == NULL){
					nodetemp->next = NULL;
					tail = nodetemp;
				}
				
				curr->next = nodetemp;
				return;
			}
			
			int get(int pos){
				Node* node3 = head;
				int count = 1; //index starts from 1
				
				while(node3!=NULL && count < pos){
					node3 = node3->next;
					count++;
				}
				return node3->data;
			}

			void display(){
				Node *p = head;
				while(p != NULL){
					cout << p->data << " ";
					p = p->next;
				}
				cout << endl;
				delete p;
				return;
			}
			
			int getSum(){
				int sum = 0;
				Node* p = head;
				while(p != NULL){
					sum+=p->data;
					p = p->next;
				}
				return sum;
			}

};
