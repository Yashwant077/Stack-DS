#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

void setStack(struct Stack* s)
{
    s->top = -1;
    printf("Enter the size for stack::");
    scanf("%d",&(s->size));
    printf("Your stack size is %d\n",s->size);
    s->arr = (int*)malloc((s->size)*sizeof(int));
    printf("Your Stack set Successfully.\n");
} 

int isEmpty(struct Stack* s)
{
    if(s->top == -1)
    {
        printf("\nStack is Empty.\n");
        return 1;
    }
    return 0;
}

int isFull(struct Stack* s)
{
    if(s->top == (s->size)-1)
    {
        printf("\nStack is Full.\n");
        return 1;
    }
    return 0;
}

void push(struct Stack* s)
{
    if(isFull(s)==1)
    {
        return;
    }
    int num;
    printf("There is already %d elements in Stack\n",(s->top)+1);
    printf("Enter the element you want to push::");
    scanf("%d",&num);
    s->top += 1;
    s->arr[s->top] = num;
}

void pop(struct Stack* s)
{
    if(isEmpty(s))
    {
        return;
    }
    else
    {
        printf("Size of the Stack is::%d\n",(s->size));
        printf("Total No. of Elements in the Stack::%d\n",(s->top)+1);
        int val = s->arr[s->top];
        s->top -= 1;
        printf("Top Element %d is popped Successfully.\n",val);
        printf("Total No. of Elements in the Stack::%d\n",(s->top)+1);
        return;
    }
}

void printStack(struct Stack* s)
{
    if(isEmpty(s)==1)
    {
        return;
    }
    printf("Total No. of Elements in the Stack::%d\n",(s->top)+1);
    printf("Elements in the stack::");
    for(int i=(s->top); i>=0; i--)
    {
        printf("\n\t%d::%d",i,s->arr[i]);
    }
}

void peek(struct Stack* s)
{
    if(isEmpty(s)==1)
        return;
    int indx;
    printf("Enter the index no.::");
    scanf("%d",&indx);
    if(indx<0)
    {
        printf("Enter a Valid index no.::");
        scanf("%d",&indx);
    }
    printf("Element at Index no. %d is:: %d",indx,(s->arr[indx]));
}

int main()
{
    struct Stack* s;
    int ch;
    do
    {
        printf("\nEnter your choice::"
               "\n1. Set Stack"
               "\n2. Push"
               "\n3. Pop"
               "\n4. Peek"
               "\n5. Print Stack"
               "\n0. Quit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            setStack(s);
            break;

        case 2:
            push(s);
            break;

        case 3:
            pop(s);
            break;

        case 4:
            peek(s);
            break;
            
        case 5:
            printStack(s);
            break;
        
        case 0:
            exit(1);
        
        default:
            printf("Please Enter a valid choice.");
            break;
        }
    } while (ch != 0);
    
    return 0;
}
