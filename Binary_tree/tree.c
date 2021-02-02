#include<stdio.h>
#include<stdlib.h>
struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node *search(struct node *root, int skey);

struct node
{
    int data;
    struct node *left,*right;
};

int main(int argc, char const *argv[])
{
    struct node *root;
    int *ptr;
    
    root=0;
    int choice,skey;
    while (1)
    {
        printf("1.Create\n");
        printf("2.Preorder\n");
        printf("3.Inorder\n");
        printf("4.Postorder\n");
        printf("5.Serach\n");
        printf("6.Quit\n");
        
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                root = create();
                
                break;
            case 2:
                printf("Preorder is:\n");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder is:\n");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("postorder is:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the Element to be searched\n");
                scanf("%d",&skey);
                root = search(root,skey);
                if(root==0)
                {
                    printf("key is not found\n");
                }
                else
                {
                    printf("key is found\n");
                }
                
                break;



            case 6:
                exit(1);


        default:
            printf("wrong choice\n");
            break;
        }
    }   
    
    return 0;
}
struct node * create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data(-1 for no node)\n");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left=create();
    printf("Enter Right child of %d\n",x);
    newnode->right=create();

    return newnode;

}
void preorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
struct node *search(struct node *root, int skey)
{
    while (root!=0)
    {
        if (skey < root->data)
        {
            root = root->left;
        }
        else if (skey > root->data)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return 0;
}
        
    