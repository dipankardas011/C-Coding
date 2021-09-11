#include <stdio.h>
#include <stdlib.h>

typedef struct dll{
    struct dll *prev;
    int data;
    struct dll *next;
}node;

void input(node *start){
    int x;
    start->prev=NULL;
    while(1){
        printf("enter the number\n");
        scanf("%d",&start->data);
        printf("\tENTER 1 TO CONTINUE\n");
        scanf("%d",&x);
        if(x==1){
            start->next=(node *)malloc(sizeof(node));
            start->next->prev=start;
            start=start->next;
        }
        else{
            start->next=NULL;
            return ;
        }
    }
}

void insert_pos(node *start, int data, int pos){
    int k=1;
    node *new,*temp;
    new = (node *)malloc(sizeof(node));
    new->data=data;
    if(!new){
        printf("\n~~~~  MEMORY ERROR!  ~~~~\n");
        return ;
    }
    if(pos==1){
        new->next=start;
        new->prev=NULL;
        start->prev=new;
        start=new;
        return;
    }
    temp=start;
    while((k<pos-1) && (temp->next!=NULL)){
        temp=temp->next;
        k++;
    }
    if(temp->next==NULL){
        new->next=NULL;
        new->prev=temp;
        temp->next=new;
    }
    else{
        new->next=temp->next;
        new->prev=temp;
        temp->next->prev=new;
        temp->next=new;
    }
}

void remove_pos(node *start, int position){
    
    int k=1;node *temp=start;
    if(start == NULL){
        printf("\n~~~~~  ERROR! EMPTY LIST  ~~~~\n");
        return;
    }
    if(position==1){
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        return ;
    }
    
    while((k<position-1) && (temp->next!=NULL)){
        k++;
        temp=temp->next;
    }
    node *temps;
    if(temp->next==NULL){
        temps=temp->prev;
        temps->next=0;
        //free(temp);
    }
    else{
        temps=temp->prev;
        temps->next=temp->next;
        temp->next->prev=temps;
        //free(temp);
    }
}

void display(node *ptr){
    printf("prev\t\tDATA\t\tnext\n");
    while(ptr){
        printf("%8u\t%8d\t%8u\n",ptr->prev,ptr->data,ptr->next);
        ptr=ptr->next;
    }
}

int count(node **p){
    int c=0;
    node *a=*p;
    while(a){
        c++;
        a=a->next;
    }
    return c;
}
void print_m(int n){

    for(int i=1;i<=n;i++)
        printf("****************************       ");
    printf("\n");
}
void display3(node **start, int x){
    node *a=*start;
    if(a==NULL){
        printf("ERROR! list is empty\n");
        return ;
    }
    else{
        printf("\nLink List present\n");
        int mm=3;
        int k;
        for(int i=1;mm=3,i<=mm;mm=x-mm,i++){
            if(a){
                print_m(mm);
            }
            else
            {
                return;
            }
            
            k=1;
            while(k<=mm){
                printf("|%8u|%8d|%8u|",a->prev,a->data,a->next);
                a=a->next;
                if(a!=NULL){
                    k++;
                    printf("  <->  ");
                }
                else
                break;
            }
            printf("\n");
            print_m(mm);
            printf("\n\n\n");
        }
    }
    //display 3.0
}

void delete_list(node **start){
    node *temp, *p;
    p=*start;
    while(p){
        temp=p->next;
        free(p);
        p=temp;
    }
    *start=NULL;
}

int main(){
    int m,x;
    printf("\nwelcome to double link list\n");
    node *head;
    head=(node *)malloc(sizeof(node));
    input(head);
    display(head);
    m=count(&head);
    display3(&head,m);
    printf("\nENTER THE DATA AND POSITION FOR INSERTION\n");
    scanf("%d%d",&x,&m);
    insert_pos(head,x,m);
    m=count(&head);
    display3(&head,m);
    printf("\nENTER THE POSITION FOR DELETION\n");
    scanf("%d",&m);
    remove_pos(head,m);

    m=count(&head);
    display3(&head,m);
    display(head);

    delete_list(&head); // last step;
    return 0;
}