/*
to print the fabonacii series
*/
#include <stdio.h>

void main(){
    int n;
    printf("enter the n\n");
    scanf("%d",&n);
    for(int i = 0; i <= n; i++){
        for(int j = n-1; j >= i; j--)
            printf("  ");
        for(int j=i;j>=0;j--)
            printf("%d ",j);
        for(int j = 1; j <= i; j++)
            printf("%d ",j);
        printf("\n");
    }
}