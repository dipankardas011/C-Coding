/*
    QUEUE USING LINKLIST IMPLEMENTATION
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_linklist{
    int data;
    struct queue_linklist *next;
}que;

que *front=NULL;
que *rear=NULL;

void input(int val){
    que *temp=(que *)malloc(sizeof(que));
    if(!temp){
        printf("~~~ MEMORY ALLOCATION ERROR! ~~~\n");
        return ;
    }
    temp->data=val;
    temp->next=NULL;
    if(rear==NULL){
        rear=temp;
        front=rear;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

int pop(){
    que *temp;
    if(front==rear && rear==NULL)
        return INT_MIN;
    int x;
    x=front->data;
    temp=front;
    front=front->next;
    if(rear==temp)
        rear=rear->next;
    free(temp);
    return x;
}

void display(){

    if(front==rear && rear==NULL){
        printf("EMPTY QUEUE\n");
        return ;
    }
    que *f=front, *r=rear;
    printf("\n\n~~~~~~~~~~~\nDATA\t\tID\n");
    int i=1;
    printf("------------------------    -------------------------    -------------------------\n");
    while(f!=r){
        if(i<=3){
            //printf("-------------------------\n");
            printf("| %8d | %9u | -> ",f->data,f->next);
            // printf("-------------------------\n");
            f=f->next;
            i++;
        }
        if(i==4){
            i=1;
            printf("\n------------------------    -------------------------    -------------------------\n\n");
            printf("------------------------    -------------------------    -------------------------\n");
        }
    }
    /* the last element is not printed as it is front==rear */
    if(i<=3){
        printf("| %8d | %9u |\n",f->data,f->next);
        printf("------------------------    -------------------------    -------------------------\n\n");
    }
    else{
        printf("\n------------------------    -------------------------    -------------------------\n\n");
        printf("\n| %8d | %9u |\n",f->data,f->next);
        printf("\n------------------------    -------------------------    -------------------------\n\n");
    }
}

void delete(){
    que *t;
    
    while(front!=rear){
        t=front;
        free(front);
        t=t->next;
        front=t;
    }
    free(t);
}
int main(){
    system("cls");
    printf("\nWELCOME TO THE QUEUE IN LINKLIST\n");
    int m;
    do{
        printf("Enter 1 to insert, 2 to delete, 3 to display\n");
        scanf("%d",&m);
        switch(m){
            case 1:printf("enter the number\n");
            scanf("%d",&m);
            input(m);
            break;

            case 2:m=pop();
            if(m==INT_MIN)printf("^~~~~ CANNOT REMOVE FURTHER\n");
            else{
                printf("the poped element: %d\n",m);
            }
            break;

            case 3:display();
            break;
            default: printf("^~~~~~ wrong key pressed\n");
        }
        printf("\t\tENTER 1 TO CONTINUE\n");
        scanf("%d",&m);
    }while(m==1);
    delete();
    return 0;
}