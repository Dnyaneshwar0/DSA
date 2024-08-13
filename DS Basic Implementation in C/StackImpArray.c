#include<stdio.h>
#include<stdlib.h>

int* arr;
int capacity =1;
int top = -1;

void push(int value){
    if(capacity == top+1){
        capacity *= 2;
        // int temp[capacity];
        // for(int i=0; i<=top; i++){
        //     temp[i] = arr[i];
        // }
        // arr = temp;
        int* temp =realloc(arr,capacity*sizeof(int));
        arr = temp;
    }
    
    top++;
    arr[top]= value;
}

void pop(){
    if(top == -1){
        printf("Stack Empty");
    }
    top--;
}

void topelement(){
    if(top == -1){
        printf("Stack Empty");
    }
    printf("%d", arr[top]);
}

int size(){
    return top+1;
}

void print(){
    for(int i=top; i>=0; i--){
        printf("%d -> ",arr[i]);
    }
    printf("NULL");
}
int main(){
    arr = (int*)malloc(sizeof(int));
    push(5);
    push(7);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    
}