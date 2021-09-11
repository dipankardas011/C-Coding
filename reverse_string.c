/*
reverse the string 
e.g.: "ABC" --> "CBA"
*/
#include <stdio.h>
#include <string.h>

void rev_str(char *s, char *p, int l, int i){
    if(l>=0){
        //printf("%c\n",*(s+l));
        *(p+i) = *(s+l);
        rev_str(s,p,l-1,i+1);
    }
}
int main(){
    char str[20];
    char p[20]="\0";
    printf("enter the string: ");
    scanf("%[^\n]",str);
    int len = strlen(str);
    rev_str(str, p, len-1, 0);
    printf("%s\n",p);
    return 0;
}