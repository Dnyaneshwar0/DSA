#include<stdio.h>
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

int empty()
{
    if(stk.ht==0)
    {
        return 1;
    }
    return 0;
}

void toPostfix(char eq[])
{
    // Stack<Character> stk=new Stack<Character>();
    for(int i=0;i<strlen(eq);i++)
    {
        char ch=eq[i];
        // if(Pattern.matches("[+*(/-]", Character.toString(ch)))
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(')
        {
            if(empty())
            {
                push(ch);
            }
            else if(ch=='(' || peek()=='(' || ((ch=='*' || ch=='/') && (peek()=='+' || peek()=='-')))
            {
                push(ch);
            }
            else
            {
                // postfixEq+=pop();
                printf("%c", pop());
                push(ch);
            }
        }
        else if(ch==')')
        {
            while(peek()!='(')
            {
                // postfixEq+=pop();
                printf("%c", pop());
            }
            pop();
        }
        else
        {
            // postfixEq+=ch;
            printf("%c", ch);
        }
    }
    
    while(!empty())
    {
        // postfixEq+=pop();
        printf("%c", pop());
    }
    // System.out.println(postfixEq);
}


// int calc()
// {
//     Stack<Integer> stk=new Stack<Integer>();
//     for(int i=0;i<postfixEq.length();i++)
//     {
//         char ch=postfixEq.charAt(i);
//         if(ch>47 && ch<58)
//         {
//             stk.push(-48+(int)ch);
//         }
//         else
//         {
//             int b=stk.pop();
//             int a=stk.pop();
//             switch (ch) 
//             {
//                 case '+':
//                     stk.push(a+b);
//                 break;
//                 case '-':
//                 stk.push(a-b);
//                 break;
//                 case '*':
//                 stk.push(a*b);
//                 break;
//                 case '/':
//                 stk.push(a/b);
//                 break;
//             }
//         }
//     }
//     return stk.pop();
// }

int main()
{
    char str[50];
    printf("Enter string:");
    scanf("%s",str);
    toPostfix(str);
    return 0;
}