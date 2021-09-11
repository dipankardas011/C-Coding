#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
    int data;
    struct linklist *next;
}node;

node *create_memory(){
    node *t;
    t = (node *)malloc(sizeof(node));
    if(t==NULL){
        printf("\nmemory error\n");
        exit(0);
    }
    t->next=NULL;

    return t;
}

void input(node **p, int val){
    node *temp;
    if(!*p){
        // no elements present
        *p=create_memory();
        (*p)->data=val;
        return ;
    }
    temp=*p;
    while(temp->next)
        temp=temp->next;
    node *t=create_memory();
    t->data=val;
    temp->next=t;
    return;
}

void display(node *p){
    while(p){
        printf("|%d|%u|\n",p->data,p->next);
        p=p->next;
    }
}

void display_circular(node *p){
    node *start=p;
    do{
        printf("|%d|%u|\n",start->data,start->next);
        start=start->next;
    }while(p!=start);
}

void create_circular(node **p){
    node *start=*p;
    node *m=*p;
    while(m->next!=NULL)
        m=m->next;
    m->next=start;
}

node *reverse_link_list(node *start){
    node *temp, *curr;
    node *prev = NULL;
    if(start!=NULL){
        curr=start;
        temp=curr;
        while(curr->next!=start){
            curr=curr->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        temp->next=prev;
        start->next=temp;
        start=temp;
    }
    return start;
}

/*
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    
    SinglyLinkedListNode* curr=llist;
    SinglyLinkedListNode* next=llist;
    SinglyLinkedListNode* prev=NULL;
    
    while(curr){
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    llist=prev;
    return llist;
}*/

int main(){
    node *head=NULL;
    int x,m;
    do{
        m=0;
        printf("enter the elements\n");
        scanf("%d",&x);
        input(&head,x);
        printf("enter 1 to continue\n");
        scanf("%d",&m);
    }while(m==1);
    display(head);
    printf("\nconverted to circular link list\n");
    create_circular(&head);
    display_circular(head);
    printf("\nconverted to reverse circular link list\n");
    node *head1;
    head1=reverse_link_list(head);
    display_circular(head1);
    return 0;
}