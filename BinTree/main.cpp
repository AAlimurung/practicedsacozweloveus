#include <iostream>
#include <stdexcept>
#include "mybinarytree.h"
using namespace std;

int main() {
	Tree* tree = new MyBinaryTree();
	node* fifty = tree->addRoot(50); //parent of the tree
	try {
		tree->addRoot(40); //check if naa pay root
	} catch (exception& e) {
		cout << e.what();
	} 
	node* thirty = tree->addLeft(fifty, 30); //parent of the subtree
	tree->addLeft(thirty, 10); //left ni 30 kay si 10
    tree->addRight(thirty, 60); //right ni 30 kay si 60
    
    node* twenty = tree->addRight(fifty, 20); //siblings sila ni 30
    tree->print(fifty);
    
    tree->print(fifty);
    cout << "Removed: " << tree->remove(thirty) << endl; //removeing 30

    cout << "Height: " << tree->height(thirty) << endl;
    cout << "Depth: " << tree->depth(fifty) << endl;

    cout << "Removed: " << tree->remove(twenty) << endl; //removing 20 
    tree->print(fifty);
    tree->print(thirty);
	return 0;
}