#include"queue.h"
#include"linkedlist.h"

class Singlyqueue : public Queue{
    LinkedList* list;
    public:
        Singlyqueue(){
            list = new LinkedList();
        }

        void enQ(int n){
            list->addLast(n);
        }
        
        int deQ(){
            return list->removeFirst();
        }
        
        int front(){
            return list->getPos(1);
        }
        
        int size(){
            return list->getSize();
        }
        
        bool isEmpty(){
            return size() == 0;
        }
        
        void print(){
            list->print();
        }
};