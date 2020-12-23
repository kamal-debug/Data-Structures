#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a[50],size,i,num,pos;
    printf("Enter Size of array\n");
    scanf("%d",&size);
    printf("Enter the Element in The Array\n");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter The Data U want to Insert\n");
    scanf("%d",&num);
    printf("Enter the Position\n");
    scanf("%d",&pos);
    for ( i = size-1; i > pos-1; i--)
    {
        a[i+1]=a[i];

    }
    a[pos-1]=num;
    size++;
    printf("Resultant Array\n");
    for ( i = 0; i < size; i++)
    {
        printf("%d",a[i]);
        printf("\n");
    }

    
    return 0;
}
