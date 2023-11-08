#include"queue.h"
#include"linkedlist.h"
using namespace std;

class Doublyqueue : public Queue{
    LinkedList* list;

    public:
        Doublyqueue(){
            list = new LinkedList();
        }
        void addFirst(int n){
            list->addHead(n);
        }
        
        void addLast(int n){
            list->addTail(n);
        }
        void removeFirst(){
            list->removeHead();
        }
        void removeLast(){
            list->removeTail();
        }
        
        int front(){
            return list->getPos(1);
        }
        
        int rear(){
            return list->getPos(size());
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