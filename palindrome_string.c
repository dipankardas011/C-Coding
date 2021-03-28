/*
to check for the palindrome string
*/
#include <string.h>
#include <stdio.h>
int main(){
    char x[20], y[20];
    printf("enter the string\n");
    scanf("%s",x);
    int len = strlen(x);
    int i;
    for(i=0;i<len;i++){
        y[i]=x[len-i-1];
    }
    y[i]='\0';
    printf("%s\n",y);
    (strcmpi(x, y) == 0)? printf("palindromic world\n") : printf("not a palindromic word\n");
    return 0;
}