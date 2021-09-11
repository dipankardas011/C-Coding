#include <stdio.h>
int main(){
    char x[100];
    int len=0;
    printf("enter a sentence\n");

    int i,j;
    for(i=0;i<100;i++){
        scanf("%c",&x[i]);
        if(x[i] == '\n') break;
        else{len++;}
    }
    x[i]=' ';
    x[++i] = '\0';
    len++;

    printf("the words:\n");
    int m=0;
    for(i=0; i<len;i++){
        if(x[i] == ' '){
            goto word;
            ret:
            m = i+1;
        }
    }
    return 0;

    word:
    for(j=m; j<i; j++)
        printf("%c",x[j]);
    printf("\n");
    goto ret;
}