#include <stdio.h>

void dec_to_bin(int num, int *snum){
    /*give the number to be converted followed by the pointer array to store*/
    if(num > 0){
        *snum++ = num%2;
        dec_to_bin(num/2, snum);
    }
}

int main(){
    int N;
    printf("enter the decimal no:\n");
    scanf("%d",&N);
    int arr[32]= {0};
    dec_to_bin(N, arr);
    for(int i=31;i>=0;i--)
        printf("%d",arr[i]);
    return 0;
}