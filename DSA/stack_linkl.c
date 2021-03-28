/*
stack using linklist implementation
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}stack;

void push(stack **top, int val){
    stack *tem;
    tem=(stack *)malloc(sizeof(stack));
    if(!tem){
        printf("\n~~~ MEMORY ERROR ~~~\n");
        return ;
    }
    tem->data=val;
    tem->next=*top;
    *top=tem;
}

int pop(stack **top){
    stack *temp=*top, *p;
    if(!temp)
        return -999;
    int x=temp->data;
    p=*top;
    temp=temp->next;
    free(p);
    *top=temp;
    return x;
}

void display(stack *p){

    if(!p){
        printf("~~~~ EMPTY stack ~~~~\n");
        return;
    }
    printf("\n~~~~~~~~~~~~~\n\n|        |\n|        |\n");
    while(p){
        printf("|%8d|\n----------\n",p->data);
        p=p->next;
    }
    printf("  TOP=0\n~~~~~~~~~~~~~\n");
}

void delete_stack(stack **top){
    stack *ptr=*top;
    stack *temp;

    while(ptr->next){
        temp=ptr->next;
        free(ptr);
        ptr=temp;
    }
    free(ptr);
}

int main(){
    system("cls");
    printf("\nWELCOME TO STACK IN LINKLIST IMPLEMENTATION\n\n");
    stack *top=NULL;
    int m;
    do{
        printf("Enter 1 to input, 2 to pop and 3 to display\n");
        scanf("%d",&m);
        switch(m){
            case 1:printf("Enter the element\n");
            scanf("%d",&m);
            push(&top, m);
            break;
            case 2:m=pop(&top);
            if(m==-999)printf("\nEMPTY\n^~~~~~~~~~\n");
            else printf("element poped: %d\n",m);
            break;
            case 3:display(top);
            break;
            default:return 0;
        }
        printf("\t\tENTER 1 TO CONTINUE\n");
        scanf("%d",&m);
    }while(m==1);

    delete_stack(&top);
}