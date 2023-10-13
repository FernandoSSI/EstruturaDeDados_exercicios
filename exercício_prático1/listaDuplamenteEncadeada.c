
#include <stdio.h>
#include <stdlib.h>

//node
typedef struct node{
    int value;
    struct node * next;
    struct node * prev;
}node;

// start and end pointers
node * first = NULL;
node * last = NULL;
int size = 0;

// add function
void add(int value, int pos){
    
    if(pos <= size && size >=0){
        //creating a new node
        node * newNode = malloc(sizeof(node));
        newNode -> value = value;
        newNode -> next = NULL;
        newNode -> prev = NULL;
        
        // if the new node is the first
        if(first == NULL){
            first = newNode;
            last = newNode;
        //if the new node is added in first position
        }else if(pos == 0){
            newNode -> next = first;
            first -> prev = newNode;
            first = newNode;
        //if the new node is added in last position
        } else if(pos == size){
            last -> next = newNode;
            newNode -> prev = last;
            last = newNode;
        // if the new node is added in the middle
        } else{
            node * aux = first;
            for(int i=0; i < pos; i++){
                aux = aux -> next;
            }
            newNode -> next = aux;
            newNode -> prev = aux -> prev;
            newNode -> next -> prev = newNode;
            newNode -> prev -> next = newNode;
        }
        size++;
    } else{
        printf("It is not possible to add to any of these  positions");
    }
    
}

// delete function
void del(int pos){
    if(pos <= size && pos >=0){
        //delete the first node
        if(pos == 0){
            node * trash = first;
            first = first -> next;
            first -> prev = NULL;
            free(trash);
        //delete the last node
        } else if (pos == size -1){
            node * trash = last;
            last = last -> prev;
            last -> next = NULL;
            free(trash);
        //delete a middle node
        } else{
            node * trash = first;
            for(int i=0; i<pos; i++){
                trash = trash -> next;
            }
            trash -> prev -> next = trash -> next;
            trash -> next -> prev = trash -> prev;
            free(trash);
        }
        size--;
    } else {
        printf("it's not possible delete any of these positions");
    }
}
//print
void print(){
    node * aux = first;
    while(aux != NULL){
        printf("%d \n", aux->value);
        aux = aux->next;
    }
}

int main() {
    
    add(10, 0);
    add(9, 0);
    add(7, 2);
    add(11, 3);
    add(2, 1);
    add(20, 5);
    
    del(4);
    del(3);
    del(0);
    
    print();
    return 0;
}