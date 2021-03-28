#include <stdio.h>
#include <string.h>
int main(){
    char str[500];
    printf("enter a valid DNA SEQUENCE FOR THE FORMAYION OF M-RNA: \n");
    scanf("%s", &str);
    int len;
    len = strlen(str);
    char x[100];
    char y;
    for(int i = 0; i < len; i++){
        if(str[i] == 'A'){
            y = 'U';
            strncat(x,&y,1);
        }
        else if(str[i] == 'T'){
            y = 'A';
            strncat(x,&y,1);
        }
        else if(str[i] == 'G'){
            y = 'C';
            strncat(x,&y,1);
        }
        else if(str[i] == 'C'){
            y = 'G';
            strncat(x,&y,1);
        }
        else{
            printf("******ERROR*******");
            return 0;
        }
    }
    printf("M-RNA SEQUENCE = %s\n",x);
    /* codons */
    if(len%3 != 0){
        printf("******ERROR the length of string is invalid*******");
        return 0;
    }
    printf("\n");
    for(int j = 0; j <= len-3;j+=3){
        printf("%c%c%c ",x[j],x[j+1],x[j+2]);
    }
    return 0;
}