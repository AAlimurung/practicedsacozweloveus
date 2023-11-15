#include"tree.h"
#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include<algorithm>
using namespace std;

class MyBinaryTree : public Tree{
    node* root;
    int size;

    public:
        MyBinaryTree(){
            root = nullptr;
            size = 0;
        }

        node* addRoot(int n){
            if(!root){
                node* newton = (node*)calloc(1,sizeof(node));
                newton->elem = n;
                size++;
                root = newton;
                return newton;
            }
            throw logic_error("Naa nay root\n");
        }

        node* addLeft(node* p, int n){
            if(!p->hidari){
                node* newton = (node*)calloc(1,sizeof(node));
                newton->elem = n;
                newton->parent = p;
                size++;
                p->hidari = newton;

                return newton;
            }
            throw logic_error("Naa nay left\n");
        }

        node* addRight(node* p, int n){
            if(!p->migi){
                node* newton = (node*)calloc(1,sizeof(node));
                newton->elem = n;
                newton->parent = p;
                size++;
                p->migi = newton;

                return newton;
            }
            throw logic_error("Naa nay right\n");
        }

        int remove(node* p){
            int aps = p->elem;
            //error if p has two children
            if(p->hidari != nullptr && p->migi != nullptr){
                cout << "Error. Cannot remove when there are two children." << endl;
                return 0;
            }

            //remove p (parent)
            node* temp = p->parent;
            if(temp->hidari == p){
                free(p);
                temp->hidari = nullptr;
            } else if(temp->migi == p){
                 free(p);
                 temp->migi = nullptr;
            }
            size--;
            return aps;
        }

        int depth(node* p){  //p = given node
            if(!p){  //from the given level
                return -1;
            }
            
            //1 + depth(p)
            return 1+depth(p->parent);
        }
        
        int height(node* root){
            if(!root){ //if walay root
                return -1;
            }

            int l = height(root->hidari); 
            int r = height(root->migi);

            //1+max(p's children)
            return max(l, r) + 1;
        }


        void print(node* n){
            if(n){
                cout << n->elem << endl;
                if(n->hidari){
                    cout << ">L: ";
                    print(n->hidari);
                }
                if(n->migi){
                    cout << "R<: ";
                    print(n->migi);
                }
            }
        }
};