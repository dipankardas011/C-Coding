/*
************************************************************
This program of binary search
************************************************************
*/
#include <stdio.h>
int main(){
    int arr[10] = {2,4,6,7,3,9,1,0,11,10};
    int l,r;
    l=0;
    r=10-1;
    int avg=0,search;
    printf("enter the elment to be searched=");
    scanf("%d",&search);
    while(l<=r){
        avg=(l+r)/2;
        if(arr[avg] > search)
            r=avg-1;
        else if(arr[avg] < search)
            l=avg+1;
        else{
            printf("found at position = %d\n", avg);
            goto end;
        }
    }
    printf("not found\n");
    end:
    return 0;
}