#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a [5],i;
    int *q=a;

    for ( i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    for ( i = 0; i < 5; i++)
    {
        printf("%d",*(q+i));
        printf("\n");
    }
    
    
    
    return 0;
}
