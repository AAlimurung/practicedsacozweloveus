#include<iostream>
#include"singlyqueue.h"
using namespace std;

int main(){
    Queue* q = new Singlyqueue();
    int n;
    char ch;

    do{
        cout << "Enter operation: ";
        cin >> ch;

        switch(ch){
            case 'e':
                cin >> n;
                q->enQ(n);
                break;
            case 'd':
                cout << "Removed: " << q->deQ() << endl;
                break;
            case 'f':
                cout << "First element: " << q->front() << endl;
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