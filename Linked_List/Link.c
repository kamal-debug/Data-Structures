#include<stdio.h>
#include<stdlib.h>

struct node *create_list(struct node *head);
void display(struct node *head);
void count(struct node *start);
struct node *insert_at_beg(struct node *head);
struct node *insert_at_end(struct node *head);
struct node *insert_after_a_given_location(struct node *head);
struct node *delete_at_beg(struct node *head);
struct node *delete_at_end(struct node *head);
struct node *delete_from_specified_position(struct node *head);

struct node{
    int data;
    struct node *next;
};
int counttemp=0;
int main(int argc, char const *argv[])
{
    struct node *head=0;
    int choice;
    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Insert at Beginning\n");
        printf("5.Insert at End\n");
        printf("6.Insert after a given Location\n");
        printf("7.Delete at Beginning\n");
        printf("8.Delete at End\n");
        printf("9.Delete from Specified Position\n");
        printf("10.Quit\n");
        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            head = create_list(head);     
            break;
        case 2:
            display(head);
            break;
        case 3:
            count(head);
            break;  
        case 4:
            head = insert_at_beg(head);
            break;  
        case 5:
            head = insert_at_end(head);
            break;
        case 6:
            head = insert_after_a_given_location(head);
            break;
        case 7:
            head = delete_at_beg(head);
            break; 
        case 8:
            head = delete_at_end(head);
            break;  
        case 9:
            head = delete_from_specified_position(head);
            break;
        case 10:
            exit(1);
        
        default:
            printf("temp Count is:%d\n",counttemp);
            printf("Wrong Choice\n");
            break;
        }
    }
    //printf("temp Count is:%d\n",counttemp);
    return 0;
}
struct node *create_list(struct node *head)
{
    struct node *newnode,*temp;
    int n,i,choice1=1;
    
    while (choice1!=0)
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
        scanf("%d",&choice1);
    }
    temp=head;
       
}
void display(struct node *head)
{
    struct node *p;
    if (head==0)
    {
        printf("list is empty\n");
    }
    p=head;
    printf("List is: \n");
    while (p!=0)
    {
        printf("%d",p->data);
        p=p->next;
        printf("\t");
        
    }
    printf("\n");
    
}
void count(struct node *head)
{
    struct node *p;
    int cnt =0;
    p=head;
    while (p!=0)
    {
        p = p->next;
        cnt++;
    }
    printf("Number Of elements In List -> %d\n",cnt);
    counttemp=cnt;
    
}
struct node *insert_at_beg(struct node *head)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data You want to Insert at Beginning\n");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;

}
struct node *insert_at_end(struct node *head)
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data You want to Insert at End\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while (temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    temp=head;
    
}
struct node *insert_after_a_given_location(struct node *head)
{
    printf("temp Count is %d:\n",counttemp);
    struct node *newnode,*temp;
    int pos,i=1;
    printf("Enter The Position\n");
    scanf("%d",&pos);
    if(pos>counttemp)
    {
        printf("Invalid Position\n");
    }
    else
    {
    
        newnode=(struct node *)malloc(sizeof(struct node));
        temp=head;
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        printf("Enter Data You want to Insert at End\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
        temp=head;
    }
      
}
struct node *delete_at_beg(struct node *head)
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("No Node to delete\n");
    }
    else
    {
        head=head->next;
        free(temp);
    }
    temp=head;   
}
struct node *delete_at_end(struct node *head)
{
    struct node *temp,*prevnode;
    temp=head;
    while (temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if (temp==head)
    {
        head=0;
    }
    else
    {
        prevnode->next=0;
    }
    free(temp);
    temp=head;
}
struct node *delete_from_specified_position(struct node *head)
{
    struct node *temp,*nextnode;
    int pos,i=1;
    temp=head;
    printf("Enter Position\n");
    scanf("%d",&pos);

    while (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(nextnode);
    temp=head;
}
    
    

