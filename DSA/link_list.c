#include <stdio.h>
#include <stdlib.h>


typedef struct student {
    char name[20];
    int age;
    struct student *next;
}node;

void input (node *ptr){
    int m;
    
    while(1){
        printf("enter the name,age\n");
        scanf(" %[^\n]",ptr->name);
        scanf("%d",&ptr->age);
        printf("enter 1 to continue the input\n");
        scanf("%d",&m);
        if(m!=1){
            ptr->next=0;
            return;
        }
        else{
            ptr->next = (node *)malloc(sizeof(node));
            ptr = ptr->next;
        }
    }
}

void display(node *ptr){
    printf("name\t\tage\taddress\n");
    while(ptr != NULL){
        printf("%s\t%d\t%u\n",&ptr->name,ptr->age,ptr->next);
        ptr=ptr->next;
    }
}

int count(node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void insert_end (node *p){
    node *new;
    new = (node *)malloc(sizeof(node));
    printf("\nenter the name,age\n");
    scanf(" %[^\n]",new->name);
    scanf("%d",&new->age);
    new->next=0;
    while(p->next!=NULL)
        p=p->next;
    p->next=new;
}

node* insert_start(node *p){
    node *new;
    new = (node *)malloc(sizeof(node));
    printf("\nenter the name,age\n");
    scanf(" %[^\n]",new->name);
    scanf("%d",&new->age);
    new->next=p;
    return new;
}

void insert_pos(node *p, int pos){
    node *new,*start=p;
    new = (node *)malloc(sizeof(node));
    printf("\nenter the name,age\n");
    scanf(" %[^\n]",new->name);
    scanf("%d",&new->age);

    int index=0;
    while(start != NULL){
        
        if(index==pos-1){
            break;
        }index++;
        start=start->next;
    }
    new->next=start->next;
    start->next=new;
}

void voter_finder(node *p){
    while(p != NULL){
        if(p->age >= 18)
            printf("\n%s\nELIGIBLE FOR VOTING\n",&p->name);
        
        p=p->next;
    }
}

void delete_pos(node *p,int pos){
    int index=0;
    node *start=p;
    while(start!=NULL){
        if(index==pos-1){
            break;
        }index++;
        start=start->next;
    }

    index=0;
    while(p!=NULL){
        if(index==pos){
            break;
        }index++;
        p=p->next;
    }
    start->next=p->next;
}


int main (){
    node *head;

    head = (node *)malloc(sizeof(node));    //assigning the memory
    input(head);
    display(head);
    printf("\n%d no of nodes",count(head));

    insert_end(head);
    display(head);
    head=insert_start(head);
    display(head);
    printf("\n%d no of nodes",count(head));

    int pos;
    // insert in a given pos(0 to count-1)
    printf("\nenter the pos\n");
    scanf("%d",&pos);
    insert_pos(head, pos);
    display(head);
    printf("\n%d no of nodes",count(head));

    voter_finder(head);
    pos=0;
    printf("\nenter the pos\n");
    scanf("%d",&pos);
    delete_pos(head,pos);
    display(head);
    printf("\n%d no of nodes",count(head));
    free(head);
}