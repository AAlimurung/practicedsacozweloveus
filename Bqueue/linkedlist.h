#include<iostream>
#include"list.h"
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList : public List{
    node* head;
    node* tail;
    int s; //size

    public:
        void add(int n){
            if(!head){
                node* newton = new node;
                newton->data = n;
                newton->next = nullptr;
                head = tail = newton;
            } else {
                node* newton = new node;
                newton->data = n;
                newton->next = nullptr;
                tail->next = newton;
                tail = newton;
            }

            s++;
            return;
        }
        
        void addLast(int n){
            add(n);
        }
        
        void addFirst(int){
        }
        
        int removeFirst(){
            if(!head){
                return -1;
            }

            int aps = head->data;
            node* temp = head;
            head = head->next;
            delete temp;
            s--;

            if(s == 0){
                tail = head;
            }

            return aps;
        }
        
        int getPos(int pos){
            if(s == 0){
                return -1;
            } 

            if(pos == 1){
                return head->data;
            } else if(pos == s){
                return tail->data;
            }

            int aps = 1;
            node* temp = head;
            while(aps < pos){
                temp = temp->next;
                aps++;
            }

            return temp->data;
        }
        
        int getSize(){
            return s;
        }
        
        void print(){
            node* p = head;
            while(p){
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
            delete p;
            return;
        }
};