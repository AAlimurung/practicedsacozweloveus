#include<iostream>
#include<cstdlib>
#include"dllist.h"
using namespace std;

struct node{
	int elem;
	node* next;
	node* prev;
};

class dlinklist : public DLL{
	node* head = NULL;
	node* tail = NULL;
	int size;
	
	//add first, between, or last 
	void addMid(int num, node* header, node* trailer){
		node* newton = new node;
		newton->elem = num;
		
		newton->prev = header; //header = predecessor
		newton->next = trailer; //trailer = successor
		
		header->next = newton;
		trailer->prev = newton;
		
		size++;
	}
	
	//remove first, between, or last
	void removeNode(node* n){
		node* header = n->prev;
		node* trailer = n->next;
		
		header->next = trailer;
		trailer->prev = header;
		
		free(n);
//		n = NULL;
		size--;
	}
	
	public:
		//constructor for the sentinels
		dlinklist(){
			head = (node*) calloc (1, sizeof(node)); 
			tail = (node*) calloc (1, sizeof(node));
			
			head->next = tail;
			tail->prev = head;
			size = 0;
		}
		
		//add head
		void addH(int num){
			addMid(num, head, head->next);
		}
		
		//add tail
		void addT(int num){
			addMid(num, tail->prev, tail);
		}
		
		void addAt(int num, int pos){	
			node* temp = head->next;
			int pin = 1;
			
			if(pos < 1){
				cout << "Hatdog ka" << endl;
			}else if(pos > (size+1)){
				pos = size+1;
			}
			
			while(pin != pos){
				temp = temp->next;
				pin++;
			}
			
			node* header = temp->prev; 
			node* trailer = temp; 
			
			addMid(num, header, trailer);
		}
		
		//remove head
		void removeH(){
			if(!head){
				return;
			}
			head = head->next;
			if(head){
				free(head->prev);
				head->prev = NULL;
			} else {
				free(tail);
				tail = NULL;
			}
			
			size--;
		}
		
		//remove tail
		void removeT(){
			if(!tail){
				return;
			}
			tail = tail->prev;
			if(tail){
				free(tail->next);
				tail->next = NULL;
			} else {
				free(head);
				head = NULL;
			}
			
			size--;
		}
		
		int remove(int num){
			node* temp = head->next;
			int pos = 1;
			
			while(temp != tail){
				if(temp->elem == num){
					removeNode(temp);
					return pos;		
				}
				temp = temp->next;
				pos++;
			}			
			return -1;
		}
		
		//remove at position
		int removeAt(int pos){
//			System.out.println("Pakyu");
			node* temp = head->next;
			int pin = 1;
			
			if(pos < 1 || pos > size){
				cout << "Haha, lol" << endl; 
			}
			
			while(pin < pos){
				temp = temp->next;
				pin++;
			}					
			int data = temp->elem;
			removeNode(temp);	
			
			return data;	
		}
		
//		int removeAll(int pos)
//		int get(int pos)
//		int retain(int num)

		int corner(int a, int b){
			node* left = head->next;
			node* right = tail->prev;
			
			for(int i=1; i<a; i++){
				left = left->next;
			}
			
			for(int i=1; i<b; i++){
				right = right->prev;
			}
			
			if(left != NULL)
				left->next = right;
			else
				head = right;
				
			if(right != NULL)
				right->prev = left;
			else
				tail = left;
			
			int size2 = size-(a+b);
			size = a + b;
			
			return size2;
		}
		
//		void reverse()

		//print forward and backwards
		void print(){
			node* compass; //compass = pointer
    	if (size == 0) {
    		cout << endl;
    		cout << "Empty" << endl;
		} else {
				cout << "From HEAD: ";
	    		compass = head->next;
		    	while (compass != tail) {
		    		cout << compass->elem;
		    		if (compass->next != tail) {
		    			cout << " -> ";
					} else {
						cout << endl;
	                    break;
					}
		    		compass = compass->next;
				}
				cout << "From TAIL: ";
	    		compass = tail->prev;
		    	while (compass != head) {
		    		cout << compass->elem;
		    		if (compass->prev != head) {
		    			cout << " <- ";
					} else {
						cout << endl;
	                    break;
					}
		    		compass = compass->prev;
				}
				cout << endl;
			}
		}
	
};
