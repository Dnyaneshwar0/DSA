#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    Node* deletenode = top;
    top = top->below;
    free(deletenode);
}

char peek() {
    if (top == NULL) {
        return '\0'; 
    }
    return top->value;
}

void print() {
    Node* temp = top;
    while (temp != NULL) {
        printf("%c -> ", temp->value);
        temp = temp->below;
    }
    printf("NULL\n");
}

bool isEmpty(){
    return top == NULL;
}

int priority(char c){
    if(c == '^') return 3;
    else if(c == '*' || c =='/') return 2;
    else if(c == '+' || c =='-') return 1;
    else return -1;

}

void infixtopostfix(char* infix){
    char postfix[strlen(infix) +1];
    int j=0;
    for(int i=0; i<strlen(infix); i++){
        if(infix[i]>='A' && infix[i]<='Z' || infix[i]>='a' && infix[i]<='z' || infix[i]>='0' && infix[i]<='9'){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '('){
            push('(');
        }
        else if(infix[i] == ')'){
            while(!isEmpty() && peek()!='('){
                postfix[j] = peek();
                j++;
                pop();
            }
            pop();
        }
        else{
            if(priority(infix[i])> priority(peek())){
                push(infix[i]);
            }
            else{
                while (!isEmpty() && priority(peek()) >= priority(infix[i])) {
                if (infix[i] == '^' && peek() == '^') {
                    break;
                }
                postfix[j++] = peek();
                pop();
            }
            push(infix[i]);
            }
        }
    }
    while(!isEmpty()){
        postfix[j]= peek();
        j++;
        pop();
    }
    postfix[j] = '\0';
    printf("%s", postfix);
}

int main() {
    // "a+b+c*d*(e+f^6^6)" = ab+cd*ef66^^+*+
    char infix[20];
    printf("Enter infix expression: ");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}
