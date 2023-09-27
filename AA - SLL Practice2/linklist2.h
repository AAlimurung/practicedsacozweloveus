#include<iostream>
#include"list2.h"
//#include "node.h"
using namespace std;

struct Node{ //link list
	int data; 
	Node* tsugi = NULL; //next 
};

class LinkList : public LL{ //private - ang head and tail
	//int size; 
	Node* up; //head :)
	Node* down; //tail :)
	
	public:
		Link(){ //declare head and tail as NULL
			up = NULL;
			down = NULL;
			//size = 0;
		}
		
//		void addLast(int data){
//		}
		
		void plus(int data){
			if(up == NULL){ //add at first
				Node* link = new Node; //link = node;
				link->data = data;
				link->tsugi = NULL;
				up = link;
			}else if(down == NULL){
				Node* link = new Node;
				link->data = data;
				link->tsugi = NULL;
				up->tsugi = link;
				down = link;
			}else{
				Node* link = new Node;
				link->data = data;
				link->tsugi = NULL;
				down->tsugi = link;
				down = link;
			}
			return;
		}
		
//		void remove(int pos){
//		}
		
		void removeAt(int pos){
			if(up == NULL || pos<=0){
				cout << "Bruh, way sulod ang list." << endl;
				return;
			}else if(pos==1){
				Node* zelda = up; //zelda = temporary
				up = up->tsugi;
				delete zelda; //since wala man ko ga malloc
				return;
			}
			
			Node* epona = up; //epona = current node
			int bram = 1; //count
			
			while(epona!=NULL && bram < pos-1){
				epona = epona->tsugi;
				bram++;
			}
			
			Node* zelda = epona->tsugi;
			epona->tsugi = zelda->tsugi;
			
			if(zelda->tsugi == NULL){
				epona->tsugi = NULL;
				down = epona;
			}
			
			delete zelda;
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
		
//		int get(int pos){
//		}
		
		void display(){
//			cout << "Size: " << size << endl;
			Node* saria = up; //saria = node variable current
			
			while(saria != NULL){
				cout << saria->data << " ";
				saria = saria->tsugi;
			}
			cout << endl;
			
			delete saria;
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
