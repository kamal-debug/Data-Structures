#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};
int main(int argc, char const *argv[])
{
    struct node *head=0,*newnode,*temp;
    int choice=1,count=0;
    while(choice!=0)
    {
        newnode=(struct node *)malloc(sizeof(struct node));

        printf("Enter Data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if (head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue('0,1')\n");
        scanf("%d",&choice);

    }
    temp=head;
    printf("the List is:\n");
    while (temp!=0)
    {
        printf("%d",temp->data);
        temp=temp->next;
        count++;
        printf("\n");
    }
    printf("Elements In List: %d\n",count);
      
    return 0;
}