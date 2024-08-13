// #include<stdio.h>
// #include<stdlib.h>

struct stack
{
    int* Top;
    int ht;
};
struct stack stk;
void push(int a)
{
    *stk.Top=a;
    printf("%p",stk.Top);
    ++stk.Top;
    ++stk.ht;
}

int pop()
{
    if(stk.ht==0)
    {
        printf("Stack Empty");
        exit(0);
    }
    stk.ht--;
    stk.Top--;
    return *stk.Top;
}

int peek()
{
    // stk.ht--;
    // stk.Top--;
    return *stk.Top;
}

// int main()
// {
//     stk.Top=(int*)malloc(20*sizeof(int));
    
//     for(int i=0;i<10;i++)
//     {
//         push(i);
//         printf("Inp: %d\n",i);
//     }
//     for(int i=0;i<12;i++)
//     {
//         printf("Out: %d\n",pop());
//     }
//     return 0;
// }