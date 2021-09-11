/*
question: your name is stored in one array copy it to another array by modifying as:-
i.  insert k number of spaces b/w every consecutive character
ii. replace spaces in your name by first character of your name
(assume k = right most digit of your Roll No.)
*/
#include <string.h>
#include <stdio.h>

int main(){
    char name[20], new_name[60];
    printf("enter your name\n");
    scanf("%[^\n]",name);
    int k;
    printf("enter your roll number\n");
    scanf("%d",&k);
    k %= 10;
    int i, l = strlen(name);
    int p=0;
    for(i=0;i<l-1;i++){
        if(name[i+1] == ' ')
            new_name[p++] = name[i];

        else if(name[i] == ' ')
            new_name[p++] = name[0];

        else{
            new_name[p++] = name[i];
            for(int j=0;j<k;j++){
            	new_name[p++]='k';
            }
        }
    }
    new_name[p++]=name[i];
    new_name[p] = '\0';
    printf("\n%s",new_name);
    return 0;
}
