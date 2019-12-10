#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *left,*right;
    node(){
        left = right = NULL;
    }
};
node *root;

void Insert(int roll)
{
    if(root == NULL){ //first node in tree
        root = new node();
        root->roll = roll;
    }
    else{
        node *parent, *cur = root;
        while(cur != NULL){
            parent = cur; //keep track of parent node
            if(roll < cur->roll){
                cur = cur->left;
            }
            else cur = cur->right;
        }
        //
        node *new_node = new node();
        new_node->roll = roll;
        //
        if(new_node->roll < parent->roll) parent->left = new_node;
        else parent->right = new_node;

    }
}
void print_preorder(node *cur)
{
    if(cur == NULL) return;
    cout<<cur->roll<<endl;
    print_preorder(cur->left);
    print_preorder(cur->right);
}
int main()
{
    Insert(1);
    Insert(2);
    Insert(7);
    Insert(4);

    cout<< (root+0)->left;
    print_preorder(root);
}
