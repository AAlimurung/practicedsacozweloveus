#include<iostream>
#include"list2.h"
using namespace std;

struct Node{ //link list
	int data; 
	Node* tsugi = NULL; //next 
};

class LinkList : public LL{ //private - ang head and tail
	int size; 
	Node* up; //head :)
	Node* down; //tail :)
	
	public:
		Link(){ //declare head and tail as NULL
			up = NULL;
			down = NULL;
			size = 0;
		}
		
//		void addLast(int data){
//		}
		
		void plus(int data){
			Node* link = new Node;
			link->data = data;
			link->tsugi = NULL;
			
			if(up == NULL){
				up = link;
				down = link;
			}else{
				down->tsugi = link;
				down = link;
			}	
			size++;
			return;
		}
		
//		void remove(int pos){
//		}
		
		void removeAt(int pos){
			Node* genesis = up; //previous
			Node* revelation = up; //current
			
			if(up == NULL || pos<=0){
				cout << "Bruh, way sulod ang list." << endl;
				return;
			}else if(pos==1){
				Node* zelda = up; //zelda = temporary
				up = up->tsugi;
				delete zelda; //since wala man ko ga malloc
				size--;
				return;
			}else{
				while(pos != 1){
					genesis = revelation;
					revelation = revelation->tsugi;
					pos--;
				}
				genesis->tsugi = revelation->tsugi;
				delete revelation;
				size--;
			}
			return;
		}
		
		void addAt(int data, int pos){
			if(up == NULL || pos <= 0){
				cout << "It's empty lagi." << endl;
				return;
			}
			if(pos==1){
				Node* navi = new Node; //navi = node variable
				navi->data = data;
				navi->tsugi = up;
				up = navi;
				return;
			}
			
			Node* epona = up; //current
			int stoker = 1; //count
			
			while(epona != NULL && stoker < pos-1){
				epona = epona->tsugi;
				stoker++;
			}
			
			Node* rauru = new Node; //rauru = node variable
			rauru->data = data;
			rauru->tsugi = epona->tsugi;
			
			if(epona->tsugi == NULL){
				rauru->tsugi = NULL;
				down = rauru;
			}
			
			epona->tsugi = rauru;
			return;
		}
		
		int get(int pos){
			Node* impa = up;
			int count = 1;
			while(impa!=NULL && count < pos){
				impa = impa->tsugi;
				count++;
			}
			return impa->data;
		}
		
		void display(){
			cout << "Size: " << size << endl;
			Node* saria = up; //saria = node variable current
			
			while(saria != NULL){
				cout << saria->data << " ";
				saria = saria->tsugi;
			}
			cout << endl;
			return;
		}
		
		int getSum(){
			int sum = 0;
			Node* skull = up;
			
			while(skull!=NULL){
				sum+=skull->data;
				skull = skull->tsugi;
			}
			
			return sum;
		}
};
