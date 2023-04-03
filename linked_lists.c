#include <stdio.h>
#include <stdlib.h>
//addr of node 1 == HEAD
//final node points to NULL

//defining a struct node
//that contains the LL content in blah
//and a pointer to the next node (note that the nodes themselves have not been defined yet)
struct node{
    int blah; struct node *next;};


//function to print LL
void prt(struct node *n){
    while(n!=NULL){
        printf("%d \n", n->blah);
        n = n->next;
    }
}

//creating 3 nodes and then malloc()
//long version
/*int main(){
    struct node *head;
    struct node *a = NULL;
    struct node *b = NULL;
    struct node *c = NULL;

//these two steps can be combined by using synctactic sugar
struct node *nodename = (struct node*) malloc(sizeof(struct node));

    a = malloc(sizeof(struct node));
    b = malloc(sizeof(struct node));
    c = malloc(sizeof(struct node));

    //assigning values to the nodes
    a->blah = 2;
    b->blah = 3;
    c->blah = 4;

    //joining the nodes
    a->next = b;
    b->next = c;
    c->next = NULL;

    head = a;
    prt(head);

}*/

//instead of creating each node separately
//we can use for loops to do this
//for example, if we have 100 nodes
int main(){
    int num_nodes = 100;
    struct node *head = NULL;
    struct node *tail = NULL;
    for(int i = 0; i<=num_nodes; i++){
        struct node* new_node = malloc(sizeof(struct node));
        new_node->blah = i;
        new_node->next = NULL;
        if(head==NULL){
            head = new_node;
            tail = new_node;}
        else{tail->next  = new_node;
        tail = new_node;}
}
prt(head);
}