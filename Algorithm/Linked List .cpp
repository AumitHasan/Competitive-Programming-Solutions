#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
};
node *root = NULL, *tail=NULL;

void append_tail(int roll)
{
    if(root == NULL){
        root = new node();
        root->roll = roll;
        root->next = NULL;
        tail = root;
    }
    else{
        node *new_node = new node();
        new_node->roll = roll;
        new_node->next = NULL;
        //
        tail->next = new_node;  //add the new node after tail node
        tail =  new_node->next; //move tail pointer forward
    }
}
void append(int roll)
{
    if(root==NULL){ //If the list is empty
        root = new node();
        root->roll = roll;
        root->next = NULL;
    }
    else{
        node *cur_node = root; //make a copy of root node
        while(cur_node->next != NULL){ //Find the last node
            cur_node = cur_node->next; //go to next address
        }
        node *new_node = new node(); //create a new node
        //struct node *new_node = (struct node*)malloc(sizeof(struct node));

        new_node->roll = roll;
        new_node->next = NULL;

        cur_node->next = new_node; //link the last node with new node
    }
}
void delete_node(int roll)
{
    node *cur_node = root;
    node *prev_node = NULL;

    while(cur_node->roll != roll){ //Searching node
        prev_node = cur_node; //Save the previous node
        cur_node = cur_node->next;
    }
    //
    if(cur_node == root){ //Delete root
        node *tmp = root; //save root in temporary variable
        root = root->next; //move root forward
        delete(tmp);  //free memory
    }
    else{ //delete non-root node
        prev_node->next = cur_node->next;  //previous node points the current node's next node
        delete(cur_node); //free current node
    }
}
void add_middle(int roll,int r)
{
    node *cur_node = root;
    while(cur_node->roll != roll){
        cur_node = cur_node->next;
    }

    node *new_node = new node();

    new_node->roll = r;
    new_node->next = cur_node->next;
    cur_node->next = new_node;
}
void print()
{
    node *cur_node = root;
    while(cur_node != NULL){ //loop until you reach null
        cout<< cur_node->roll<<endl;
        cur_node = cur_node->next;
    }
}
int main()
{
    append_tail(1);
    append_tail(2);
    append_tail(6);
//    append(2);
//    append(3);
//
//    delete_node(1);
//    add_middle(2,4);

    //print();

    return 0;
}

