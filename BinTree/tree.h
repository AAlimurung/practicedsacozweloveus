#include"node.h"
class Tree{
    public:
        virtual node* addRoot(int) = 0;
        virtual node* addLeft(node*, int) = 0;
        virtual node* addRight(node*, int) = 0;
        //virtual node* attach(node*) = 0;
        virtual int remove(node*) = 0;
        //virtual int left(node*) = 0
        //virtual int right(node*) = 0;
        //virtual int set(node*, int) = 0;
        virtual void print(node* n) = 0;
        virtual int depth(node*) = 0;
        virtual int height(node*) = 0;
};