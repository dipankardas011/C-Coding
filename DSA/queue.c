/*
FIFO here the first in first out
*/

#include <stdio.h>
#include <stdlib.h>
#define L 5

int que_id[L];
int f,r=-1;


void input_elements(int a){
    if(r==-1){
        f=0;
        que_id[++r]=a;
    }
    else if(r<L-1)
        que_id[++r]=a;
    else
        printf("\nERROR! queue is full\n");
}

void remove_elements(){
    if(f>r){
        printf("EMPTY QUEUE\n");
        f=r=-1;
        return;
    }
    printf("popped element: %d\n",que_id[f++]);
}

void display(){
    if(f<=r && f!=-1){
        printf("|");
        for(int i=f;i<=r;i++)
            printf(" %d |",que_id[i]);
        printf("\n");
    }
    else
        printf("the queue is empty\n");
}

int main(){
    system("cls");
    printf("\nWELCOME TO QUEUE (array implementation)\n");

    int ch;
    do{
        printf("\nenter 1 to push elements, 2 to pop elements, 3 to display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter element to be pushed: ");
            scanf("%d",&ch);
            input_elements(ch);
            break;
            
            case 2:
            remove_elements();
            break;

            case 3:
            display();
            break;

            default: printf("INVALID input\n");
            return 0;
        }
        printf("\nenter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}