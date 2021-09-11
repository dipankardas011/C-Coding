/* to display all the asii values starting from 0 to 122
*/
#include <stdio.h>
int main(){
    int i;
    for(i=0; i<256; i++){
        printf("|%c - %d\t",i,i);
    }
    printf("\n");
    return 0;
}