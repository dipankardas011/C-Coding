/*
making the circular link list using tail pointer
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct circular{
    int data;
    struct circular *next;
}node;

node *tail=NULL;

node *create(){
    node *t=(node *)malloc(sizeof(node));
    t->next=NULL;
    return t;
}

void input(){
    int ch;
    do{
        node *newnode=create();
        printf("enter the element\n");
        scanf("%d",&newnode->data);
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("enter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch==1);
}

void display(){
    node *t=tail->next;
    if(tail == 0){
        printf("empty\n");
        return ;
    }
    do{
        printf("|%d|%u|\t",t->data,t->next);
        t=t->next;
    }while(t!=tail->next);
    printf("\n");
}

void delete(){
    node *t=tail->next, *temp;
    while(t!=tail->next){
        temp=t;
        temp=temp->next;
        free(t);
        t=temp;
    }
    free(temp);
}

int main(){
    printf("welcome\n");
    input();
    display();
    delete();
}