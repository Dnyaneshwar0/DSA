#include<stdio.h>
#include<stdlib.h>
#include "StackImpLL.h"

struct Node{
    int value;
    struct Node* below;
};
typedef struct Node Node;
Node* top = NULL;

void push(int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> value = value;
    newnode ->below =top;
    top = newnode;
}

void pop(){
    if(top == NULL){
        printf("Stack Empty\n");
        return;
    }
    Node* deletenode = top;
    top = top->below;
    free(deletenode);
}

void print(){
    Node* temp = top;
    printf("Stack Top: ");
    while(temp != NULL){
        printf("%d -> ", temp->value);
        temp =temp->below;
    }
    printf("NULL\n");
}

int peek(){
    if(top == NULL){
        printf("Empty Stack\n");
        return -1;
    }
    return top -> value;
}
int main(){
    push(7);
    push(5);
    push(6);
    push(1);
    push(5);
    push(4);
    push(0);
    push(1);
    print();
    return 0;
}