#include<iostream>
#include"doublyqueue.h"
using namespace std;

int main(){
    Queue* q = new Doublyqueue();
    int n;
    char ch;

    do{
        cout << "Enter operation: ";
        cin >> ch;

        switch(ch){
            case 'h':
                cin >> n;
                q->addFirst(n);
                break;
            case 't':
                cin >> n;
                q->addLast(n);
                break;
            case 'H':
                q->removeFirst();
                break;
            case 'T':
                q->removeLast();
                break;
            case 'f':
                cout << "First element: " << q->front() << endl;
                break;
            case 'r':
                cout << "Last element: " << q->rear() << endl;
                break;
            case 's':
                cout << "Size of queue: " << q->size() << endl;
                break;
            case '?':
                cout << "Is the queue empty? " << q->isEmpty() << endl;
                break;
            case 'p':
                q->print();
                break;
            case 'x':
                cout << "Peace" << endl;
                break;
        }
    }while(ch != 'x');

    return 0;
}