//idc if you don't like my variable name. I'm funny, and so are they.
#include<iostream>
#include<cstdlib>
using namespace std;
//practice: singly linked list with the base codes from lee
struct Node{
	int data;
	Node* tsugi; //next
};

class LL{ //class sa linked list
	Node* top; //head
	Node* tophaw; //tail
	
	public:
		Link(){ //declare them as null
			top = NULL; //head
			tophaw = NULL; //tail
		}
		
		void plus(int data){ //add elements to linked list
			if(top == NULL){ //add first
				Node* link = new Node; //link = node
				link->data = data;
				link->tsugi = NULL;
				top = link;
			}else if(tophaw == NULL){ //succeeding terms 
				Node* link = new Node;
				link->data = data;
				link->tsugi = NULL;
				top->tsugi = link;
				tophaw = link;
			}else{
				Node* link = new Node;
				link->data = data;
				link->tsugi = NULL;
				tophaw->tsugi = link;
				tophaw = link;
			}
			return;
		}
		
		void removeAt(int pos){
			if(top == NULL || pos <= 0){ //first index sa linked list is 1, not 0;
				cout << "Bruh, way sulod ang list." << endl;
				return;
			}
			if(pos == 1){
				Node* zelda = top; //zelda = temp
				top = top->tsugi;
				free(zelda); //apparently dli mogana if walay cstdlib
				return;
			}
			Node* epona = top; //epona = current;
			int dracula = 1; //dracula = count TT iknow, nerd ko sorry;
			
			while(epona != NULL && dracula < pos-1){
				epona = epona->tsugi;
				dracula++;
			}
			
			Node* zelda = epona->tsugi;
			epona->tsugi = zelda->tsugi;
			
			if(zelda->tsugi == NULL){
				epona->tsugi = NULL;
				tophaw = epona;
			}
			delete zelda;
			return;
		}
		
		void addAt(int data, int pos){
			if(top == NULL || pos <= 0){
				cout << "It's empty lagi." << endl;
				return;
			}
			if(pos==1){
				Node* navi = new Node; //new node variable.
				navi->data = data;
				navi->tsugi = top;
				top = navi;
				return;
			}
			
			Node* epona = top; //current
			int montecristo = 1; //im sorry, pero count bitaw ni
			while(epona != NULL && montecristo < pos-1){
				epona = epona->tsugi;
				montecristo++;
			}
			
			Node* rauru = new Node; //rauru = node variable
			rauru->data = data;
			rauru->tsugi = epona->tsugi;
			if(epona->tsugi == NULL){
				rauru->tsugi = NULL;
				tophaw = rauru;
			}
			epona->tsugi = rauru;
			return;
		}
		
		void display(){
			Node* saria = top; //saria = another node variable
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
			Node* skull = top; //skull = another node variable
			
			while(skull!=NULL){
				sum+=skull->data;
				skull = skull->tsugi;
			}
			
			return sum;
		}
};

int main(){
	LL* l = new LL();
	char set;
	int n, pos;
	
	cout << "a - add" << endl << "@ - addAt" << endl << "r - removeAt" << endl << "d - display" << endl << "s - sum" << endl << "x - exit" << endl;
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
				cout << "Sum of the list is: " << l->getSum() << endl;
				break;
		}
	}while(set!='x');
	
	cout << "thank you arrays." << endl;
	
	return 0;
}
