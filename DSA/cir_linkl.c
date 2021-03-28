/*  circular linklist
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct circularll{
    int data;
    struct circularll *next;
}node;

void input(node *start){
    node *head=start;
    int x;
    while(1){
        printf("enter the number\n");
        scanf("%d",&start->data);
        printf("\tENTER 1 TO CONTINUE\n");
        scanf("%d",&x);
        if(x==1){
            start->next=(node *)malloc(sizeof(node));
            start=start->next;
        }
        else{
            start->next=head;
            return;
        }
    }
}

int count(node *start){
    node *ptr=start;
    int k=0;
    if(start==NULL)
        return 0;
    do{
        k++;
        start=start->next;
    }while(ptr!=start);
    return k;
}

void display(node **head){
    node *start=*head;
    node *ptr=start;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~\nHEAD ADDRESS: %u\n",ptr);
    if(start==NULL){
        printf("~~~~ EMPTY CIRCULAR LINK LIST ~~~~\n");
        return;
    }
    printf("\nDATA\tnext_id\n");
    do{
        printf("%d\t%u\n",start->data,start->next);
        start=start->next;
    }while(start!=ptr);
    printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void insert_end(node **start,int data){
    node *current=*start;
    node *new=(node *)malloc(sizeof(node));
    if(!new){
        printf("\n~~~~  MEMEORY ERROR  ~~~~\n");
        return;
    }
    new->data=data;
    new->next=new;  // default is pointing to itself
    while(current->next != *start)
        current=current->next;
    if(*start==NULL)
        *start=NULL;
    else{
        new->next=*start;
        current->next=new;
    }
}

void insert_front(node **start, int data){
    node *current=*start;
    node *new=(node *)malloc(sizeof(node));
    if(!new){
        printf("~~~~  MEMORY ERROR  ~~~~\n");
        return;
    }
    new->data=data;
    new->next=new;
    while(current->next!=*start)
        current=current->next;
    if(*start==NULL)
        *start=new;
    else{
        new->next=*start;
        current->next=new;
        *start=new;
    }
}

void remove_front(node **start){
    //node *temp=start;
    node *current=*start;
    if(*start==NULL){
        printf("\n~~~~ LIST IS EMPTY ~~~~\n");
        return;
    }
    node *p=*start;
    while(current->next!=p)
        current =current->next;
    p=p->next;
    current->next=*start;
}

void remove_end(node **start){
    node *temp;
    node *current=*start;
    if(*start==NULL){
        printf("\n~~~~ LIST IS EMPTY ~~~~\n");
        return;
    }
    while(current->next!=*start){
        temp=current;
        current=current->next;
    }
    //free(current);
    temp->next=*start;
}

int main(){
    int x;
    printf("\nWELCOME TO THE CIRCULAR LINK LIST\n");
    node *head;
    head=(node *)malloc(sizeof(node));
    input(head);
    display(&head);
    printf("no of nodes: %d\n",count(head));

    printf("enter the element to be pushed in FRONT\n");
    scanf("%d",&x);
    insert_front(&head, x);
    display(&head);

    printf("enter the element to be pushed in END\n");
    scanf("%d",&x);
    insert_end(&head, x);
    display(&head);

    remove_front(&head);
    display(&head);

    remove_end(&head);
    display(&head);
    return 0;
}