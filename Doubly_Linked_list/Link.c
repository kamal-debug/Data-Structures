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
    struct node *prev;
};
int counttemp=0;
struct node *tail;
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
        newnode->prev=0;
        newnode->next=0;
        if (head==0)
        {
            head=temp=tail=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            tail=newnode;
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
    newnode->prev=0;
    newnode->next=0;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;

}
struct node *insert_at_end(struct node *head)
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data You want to Insert at End\n");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    temp=head;
    
}
struct node *insert_after_a_given_location(struct node *head)
{
    printf("temp Count is %d:\n",counttemp);
    struct node *newnode,*temp;
    int pos,i=1;
    printf("Enter The Position\n");
    scanf("%d",&pos);
    //if(pos>counttemp)
    //{
     //   printf("Invalid Position\n");
   // }
   // else
    //{
        temp=head;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter Data You want to Insert at End\n");
        scanf("%d",&newnode->data);
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        newnode->next->prev=newnode;
        
        printf("i is:%d\n",i);
        temp=head;
        
    //}
      
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
        head->prev=0;
        free(temp);
    }
    temp=head;   
}
struct node *delete_at_end(struct node *head)
{
    struct node *temp;
    
    if (tail==0)
    {
        printf("No Node at end\n");
    }
    else
    {
        temp=tail;
        tail->prev->next=0;
        tail=tail->prev;
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

    while (i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    temp=head;
}
    
    

