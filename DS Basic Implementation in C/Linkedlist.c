#include<stdio.h>
#include<stdlib.h>


struct Node{
    int value;
    struct Node* next;
};
typedef struct Node Node;

Node* head = NULL;

void insertatbegin(int value){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> value = value;
    temp -> next = head;
    head = temp; 
}

 void print(){
    Node* temp = head;
    printf("List: ");
    while(temp != NULL){
        printf("%d -> ",temp->value);
        temp = temp -> next;
    }
    printf("END");
}

// Node* pass = head;
// Node* ptrindex(int index){
    
//     for(int i=0; i<index; i++){
//        pass = pass->next; 
//     }
//     return &pass;
// } address of fxn var can't be returned, after exe it doesn't exist

// indexing starts from zero
void insertinbtw(int value, int index){
    if(index == 0) {
        insertatbegin(value);
        return;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->value = value;
    Node* prevnode = head;
    for(int i=0; i<index -1; i++){
        prevnode = prevnode->next;
    }
    newnode->next = prevnode->next;
    prevnode->next = newnode;     
}

void delete(int index){
    Node* prevnode = head;
    if(index ==1){
        head = prevnode->next;
        free(prevnode);
        return;
    }
    
    for(int i=0; i<index -1; i++){
        prevnode = prevnode->next;
    }
    Node* deletenode = prevnode->next;
    prevnode->next = deletenode->next;
    free(deletenode);
}

void reverse(){

}
 int main(){
    insertatbegin(5);
    insertatbegin(9);
    insertinbtw(14, 1);

    delete(1);
    print();
    return 0;
 }