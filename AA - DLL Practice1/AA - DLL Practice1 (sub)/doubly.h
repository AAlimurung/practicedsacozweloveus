#include<iostream>
#include"dll.h"
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

class doubly : public dll{
	//private
	node* head;
	node* tail;
	
	public:
		//add at head
		void addH(int num){
			node* newton = new node;
			newton->data = num;
			newton->next = NULL;
			newton->prev = NULL;
			
			if(head == NULL){
				tail = head = newton;
			}else{
				head->prev = newton;
				newton->next = head;
				head = newton;
			}
		}
		
		//add at tail
		void addT(int num){
			node* newton = new node;
			newton->data = num;
			newton->next = NULL;
			newton->prev = NULL;
			
			if(tail == NULL){
				tail = head = newton;
			}else{
				tail->next = newton;
				newton->prev = tail;
				//newton->next = NULL;
				tail = newton;
			}
		}
		
//		void addAt(int num, int pos)
		void removeH(){
			//remove head
			
		}
//		int removeT(int pos)
//		int removeAt(int pos)
//		int removeAll(int pos)

//		void reverseList(){
//			node* p1 = head;
//			node* p2 = tail;
//			
//			while(p1 < p2){
//				//dele nako
//			}
//		}
		
		//printing list normally (left to right)
		void printNorm(){
			node* compass = head;
			
			while(compass != NULL){
				cout << compass->data;
				
				if(compass->next != NULL){
					cout << " <-> ";
				}
//				else{
//					cout << " <-> NULL";
//				}
				
				compass = compass->next;
			}
			
			cout << endl;
		}
		
		//printing list in reverse (right to left)
		void printRev(){
			node* point = tail;
			
			while(point != NULL){
				cout << point->data;
				
				if(point->prev != NULL){
					cout << " <-> ";
				}
//				else{
//					cout << " <-> NULL";
//				}
				
				point = point->prev;
			}
			
			cout << endl;
		}
};
