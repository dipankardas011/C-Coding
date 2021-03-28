/*
********************************************************************
This program is about the bubble sort
********************************************************************
*/
#include <stdio.h>
void main(){
    int n;
    printf("enter the size\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements:\n");
    int i,j;

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    int t;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%d,",arr[i]);

    printf("\b \n");
}