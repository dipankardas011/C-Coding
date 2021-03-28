/*
* to swap two numbers using pointers
*/
#include <stdio.h>
void swap(int *, int *); // prototype
int main(){
    int a,b;
    printf("enter 2 numbers\n");
    scanf("%d%d",&a,&b);
    printf("a = %d , b = %d\n",a,b);
    swap(&a,&b);
    printf("a = %d , b = %d\n",a,b);
    return 0;
}
void swap(int *A, int *B){
    int t;
    t=*A;
    *A=*B;
    *B=t;
}