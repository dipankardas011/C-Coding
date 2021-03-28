/* using array implementation*/

/*
<===front               rear <====
    -------------------------
    | 3 | 5 | 6 | 7 | 8 | 1 |
    -------------------------
*/
#include <stdlib.h>
#include <stdio.h>

#define CAP 5

static int que[CAP];
int front,rear=-1;


void input_front(int x){
    if(front==-1){
        front=CAP;rear=CAP-1;
        que[--front]=x;
        
    }
    else if(front>0)
    que[--front]=x;
    else
    printf("\nFULL FROM FRONT\n");
}

void input_rear(int x){
    if(front==-1 && rear == -1){
        front,rear=0;
        que[rear]=x;
    }
    else if(rear<CAP-1){
        que[++rear]=x;
    }
    else
        printf("FULL FROM REAR\n");
}

int remove_rear(){
    int x;
    if(front>rear){
        x=-999;
    }
    else
        x=que[rear--];
    return x;
}

int remove_front(){
    int x;
    if(front>rear)
        x=-999;
    else
        x=que[front++];
    return x;
}

void display(){
    if(front!=-1 && front<=rear){
        printf("| ");
        for(int i=front;i<=rear;i++)
            printf(" %d |",que[i]);
        printf("\n");
    }
    else
        printf("\nEMPTY QUEUE\n");
}

int main(){
    system("cls");
    printf("\nWELCOME TO QUEUE (array implementation\n");
    int ch;
    do{
        printf("\nenter 1 to push from front,2 to push from rear, 3 to pop from front,4 to pop from rear, 5 to display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter element to be pushed: ");
            scanf("%d",&ch);
            input_front(ch);
            break;
            case 2:
            printf("enter element to be pushed: ");
            scanf("%d",&ch);
            input_rear(ch);
            break;
            case 3:
            ch=remove_front();
            if(ch==-999) printf("\nNO elements left\n");
            else printf("elment removed: %d\n",ch);
            break;
            case 4:
            ch=remove_rear();
            if(ch==-999) printf("\nNO elements left\n");
            else printf("elment removed: %d\n",ch);
            break;
            case 5:
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