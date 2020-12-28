#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main(int argc, char const *argv[])
{
    int choice,item;
    while (1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display the top Element\n");
        printf("4.Display all Element\n");
        printf("5.Quit\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the item to be Pushed:\n");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item = pop();
                printf("Popped item is %d\n",item);
                break;
            case 3:
                printf("Item at the Top is: %d\n",peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);

        default:
            printf("wrong choice\n");
            break;
        }
    }   
    
    
    return 0;
}
void push(int item)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = item;
}
int pop()
{
    int item;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    item = stack_arr[top];
    top--;
    return item;
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top];

}
int isEmpty()
{
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display() 
{
    int i;
    if(isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack Element are: \n");
    for ( i = top; i >=0; i--)
    {
        printf("%d",stack_arr[i]);
        printf("\t");
    }
    printf("\n");
}
    
   



