#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char value;
    struct Node* below;
};
typedef struct Node Node;
Node* top = NULL;

void push(char value) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->value = value;
    newnode->below = top;
    top = newnode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Empty\n");
        return '\0'; 
    }
    Node* deletenode = top;
    char poppedValue = deletenode->value;
    top = top->below;
    free(deletenode);
    return poppedValue;
}

void print() {
    Node* temp = top;
    while (temp != NULL) {
        printf("%c ", temp->value);
        temp = temp->below;
    }
}

bool isEmpty(){
    return top== NULL;
}
bool check(char* exp) {
    if(strlen(exp) == 0) return true;
    for (int i = 0; i < strlen(exp); i++) {
        
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }
        
        else  {
            if(exp[i] == ')'){
                if(isEmpty() || pop() != '(')
                return false;
            }
            if(exp[i] == '}'){
                if(isEmpty() || pop() != '{')
                return false;
            }
            if(isEmpty() == ']'){
                if(isEmpty() || pop() != '[')
                return false;
            }
        }
    }
    
    return top == NULL;
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%[^\n]s", exp);

    if (check(exp)) {
        printf("Valid Parenthesis\n");
    } else {
        printf("Invalid Parenthesis\n");
    }
    return 0;
}
