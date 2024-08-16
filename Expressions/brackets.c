#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    char arr[20];
    int ht;
};

struct stack stk;

void push(char ch)
{
    if(stk.ht>=20)
    {
        printf("Stack Overflow");
        exit(0);
    }
    stk.arr[stk.ht]=ch;
    ++stk.ht;
}

char pop()
{
    if(stk.ht<=0)
    {
        printf("Stack Empty");
    }
    else
    {
        --stk.ht;
        return stk.arr[stk.ht];
    }
}

char peek()
{
    if(stk.ht<=0)
    {
        printf("Stack Empty");
    }
    else
    {
        return stk.arr[stk.ht-1];
    }
}

void check(char str[])
{
    for(int i=0;i<strlen(str);i++)
    {
        char ch='0';
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(str[i]);
            continue;
        }
        else if(str[i]==')')
        {
            ch='(';
        }
        else if(str[i]=='}')
        {
            ch='{';
        }
        else if(str[i]==']')
        {
            ch='[';
        }
        else
        {
            continue;
        }
        
        if(peek()==ch)
        {
            pop();
        }
        else
        {
            printf("Brackets are not in correct order.");
            exit(0);
        }
    }
    printf("All brackets are in correct order.");
}

int main()
{
    char str[50];
    printf("Enter string:");
    scanf("%s",str);
    check(str);
    return 0;
}