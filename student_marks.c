/****************************************************************************************************
this program request the user to input the vehicle type and the period(starting month, ending month)
*****************************************************************************************************
*/
#include <stdio.h>
#include <string.h>
int main(){
    int roll[5];
    int marks[5];
    char name[5][30];
    int i,j;
    printf("*******************************************\n");
    printf("***enter the roll, name, marks obtained*****\n");
    printf("*******************************************\n");
    for(i=0; i<5; i++)
        scanf("%d %[^\n] %d",&roll[i],name[i],&marks[i]);
        
    printf("\nRoll\tName\tMarks\n\n");
    for(i=0;i<5;i++){
        printf("%d\t%s\t%d",roll[i],name[i],marks[i]);
        printf("\n");
    }
    int t=0;
    char ts[30];

    printf("===============================================\n");
    printf("based on the alphabetical order of names\n");
    printf("*******************************************\n");
    for(i=1;i<5;i++){
        for(j=1;j<=5-i;j++){
            if(strcmp(name[j-1], name[j]) > 0){
                strcpy(ts, name[j-1]);
                strcpy(name[j-1],name[j]);
                strcpy(name[j], ts);

                t=roll[j-1];
                roll[j-1] = roll[j];
                roll[j]=t;

                t=marks[j-1];
                marks[j-1]=marks[j];
                marks[j]=t;
            }
        }
    }
    printf("\nRoll\tName\tMarks\n\n");
    for(i=0;i<5;i++){
        printf("%d\t%s\t%d",roll[i],name[i],marks[i]);
        printf("\n");
    }

    printf("===============================================\n");
    printf("based on the ascending order of roll\n");
    printf("*******************************************\n");
    for(i=1;i<5;i++){
        for(j=1;j<=5-i;j++){
            if(roll[j-1] > roll[j]){
                strcpy(ts, name[j-1]);
                strcpy(name[j-1],name[j]);
                strcpy(name[j], ts);

                t=roll[j-1];
                roll[j-1] = roll[j];
                roll[j]=t;

                t=marks[j-1];
                marks[j-1]=marks[j];
                marks[j]=t;
            }
        }
    }
    printf("\nRoll\tName\tMarks\n\n");
    for(i=0;i<5;i++){
        printf("%d\t%s\t%d",roll[i],name[i],marks[i]);
        printf("\n");
    }

    printf("===============================================\n");
    printf("based on the merit list \n");
    printf("*******************************************\n");
    for(i=1;i<5;i++){
        for(j=1;j<=5-i;j++){
            if(marks[j-1]<marks[j]){
                strcpy(ts, name[j-1]);
                strcpy(name[j-1],name[j]);
                strcpy(name[j], ts);

                t=roll[j-1];
                roll[j-1] = roll[j];
                roll[j]=t;

                t=marks[j-1];
                marks[j-1]=marks[j];
                marks[j]=t;
            }
        }
    }
    printf("\nRoll\tName\tMarks\n\n");
    for(i=0;i<5;i++){
        printf("%d\t%s\t%d",roll[i],name[i],marks[i]);
        printf("\n");
    }
    printf("-------------XXX-------------------\n");
    return 0;
}