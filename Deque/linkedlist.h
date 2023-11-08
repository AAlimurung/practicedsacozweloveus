#include<iostream>
#include"list.h"
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

class LinkedList : public List{
    node* head;
    node* tail;
    int s; //size

    void addBetween(int n, node* before, node* after){
        node* newton = new node;
        newton->data = n;
        newton->prev = before;
        newton->next = after;

        before->next = newton;
        after->prev = newton;
        s++;
    }

    void removeNode(node* n){
        node* before = n->prev;
        node* after = n->next;
        
        before->next = after;
        after->prev = before;
        delete n;
        s--;
    }

    public:
        LinkedList(){
            head = new node;
            tail = new node;
            head->next = tail;
            tail->prev = head;
            s = 0;
        }

        void addTail(int n){
            addBetween(n, tail->prev, tail);
        }
        
        void addHead(int n){
            addBetween(n, head, head->next);
        }
        
        void removeHead(){
            if(!head){
                return;
            }

            head = head->next;

            if(head){
                delete head->prev;
                head->prev = nullptr;
            } else {
                delete tail;
                tail = nullptr;
            }

            s--;
        }

        void removeTail(){
            if(!tail){
                return;
            }

            tail = tail->prev;
            if(tail){
                delete tail->next;
                tail->next = nullptr;
            } else {
                delete head;
                head = nullptr;
            }

            s--;
        }

        void add(int num) {
    		addTail(num);
    	}
	
    	int remove(int num) {
    		node* curr = head->next;
    		int pos = 1;
        		while (curr != tail) {
        			if (curr->data == num) { 
        				removeNode(curr);
        				return pos;
        			}
        			curr = curr->next;
        			pos++;
        		}
    		return -1;
        }
        
        int getPos(int pos){
            if(s == 0){
                return -1;
            } 
            if(pos == 1){
                return head->next->data;
            } else if(pos == s){
                return tail->prev->data;
            }
            
            int aps = 1;
            node* temp = head;
            while(aps != pos){
                temp = temp->next;
                aps++;
            }

            return temp->data;
        }
        
        int getSize(){
            return s;
        }
        
        void print() {
        	node* curr;
        	if (s == 0) {
        		cout << "Empty" << endl;
    		} else {
    			cout << "From HEAD: ";
        		curr = head->next;
    	    	while (curr != tail) {
    	    		cout << curr->data;
    	    		if (curr->next != tail) {
    	    			cout << " -> ";
    				} else {
    					cout << endl;
                        break;
    				}
    	    		curr = curr->next;
    			}
    			cout << endl << "From TAIL: ";
        		curr = tail->prev;
    	    	while (curr != head) {
    	    		cout << curr->data;
    	    		if (curr->prev != head) {
    	    			cout << " <- ";
    				} else {
    					cout << endl;
                        break;
    				}
    	    		curr = curr->prev;
    			}
    			cout << endl;
    		}
        }
};