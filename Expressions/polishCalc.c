#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stack
{
    int arr[20];
    int ht;
};

struct stack stk;

void push(int a)
{
    if(stk.ht>=20)
    {
        printf("Stack Overflow");
        exit(0);
    }
    stk.arr[stk.ht]=a;
    ++stk.ht;
}

int pop()
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

int peek()
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

int empty()
{
    if(stk.ht==0)
    {
        return 1;
    }
    return 0;
}


int postFixCalc(char eq[])
{
    for(int i=0;i<strlen(eq);i++)
    {
        char ch=eq[i];
        if((int)ch>47 && (int)ch<58)
        {
            push(-48+(int)ch);
        }
        else
        {
            int b=pop();
            int a=pop();
            switch (ch) 
            {
                case '+':
                    push(a+b);
                break;
                case '-':
                    push(a-b);
                break;
                case '*':
                    push(a*b);
                break;
                case '/':
                    push(a/b);
                break;
            }
        }
    }
    return pop();
}


int main()
{
    char str[50];
    printf("Enter string:");
    scanf("%s",str);
    printf("Answer: %d",postFixCalc(str));
    return 0;
}