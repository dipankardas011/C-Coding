#include <stdio.h>
#include <stdlib.h>

typedef struct linklist{
    int data;
    struct linklist *next;
}node;

void input(node **start){
    node *a;
    int x;
    a=*start;
    while(1){
        printf("\nenter the number\n");
        scanf("%d",&a->data);
        printf("ENTER 1 TO CONTINUE THE INPUT\n");
        scanf("%d",&x);
        if(x==1){
            a->next = (node *)malloc(sizeof(node));
            a=a->next;
        }
        else{
            a->next=NULL;
            return;
        }
    }
}

void insert_at_pos(node **start, int data, int position){
    node *new;
    new=(node *)malloc(sizeof(node));

    new->data=data;

    if(position==1){
        new->next=*start;
        *start=new;
        return ;
    }
    else {
        int k=1;
        node *p=*start, *temp;

        while((p!=NULL)&&(k<=position-1)){
            k++;
            temp=p;
            p=p->next;
        }
        if(p==NULL){
            temp->next=new;
            new->next=NULL;
        }
        else{
            temp->next=new;
            new->next=p;
        }
        
    }
}

void delete_at_pos(node **start, int position){
    node *p,*q;
    node *a=*start;
    if(*start==NULL){
        printf("ERROR! empty\n");
        return ;
    }
    int k=1;
    p=*start;
    if(position == 1){
        a=a->next;
        free(p);
        return;
    }
    else{
        while((p!=NULL)&&(k<=position-1)){
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            printf("\nERROR! position does't exist\n");
        }
        else{
            q->next=p->next;
            free(p);
        }
    }
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
        printf("*****************       ");
    printf("\n");
}

// void display2(node **start, int x){
//     node *a=*start;
//     if(a==NULL){
//         printf("ERROR! list is empty\n");
//         return ;
//     }
//     else{
//         printf("\nLink List present\n");
//         print_m(x);
//         while(a){
//             printf("|%7d|%7u|",a->data,a->next);
//             a=a->next;
//             if(a!=NULL)
//             printf("  -->  ");
//         }
//         printf("\n");print_m(x);
//     }
//     //display 2.0
// }

void display3(node **start, int x){
    node *a=*start;
    if(a==NULL){
        printf("ERROR! list is empty\n");
        return ;
    }
    else{
        printf("\nLink List present\n");
        int mm=5;
        int k;
        for(int i=1;mm=5,i<=mm;mm=x-mm,i++){
            if(a){
                print_m(mm);
            }
            else
            {
                return;
            }
            
            k=1;
            while(k<=mm){
                printf("|%7d|%7u|",a->data,a->next);
                a=a->next;
                if(a!=NULL){
                    k++;
                    printf("  -->  ");
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

int main(){
    int n,p;
    node *head;
    head=(node *)malloc(sizeof(node));
    input(&head);

    int m=count(&head);
    display3(&head,m);

    printf("\nenter the number as well as the position where you want to insert in the linklist\n");
    scanf("%d%d",&n,&p);
    insert_at_pos(&head,n,p);
    
    m=count(&head);
    display3(&head,m);

    printf("\nenter the position to delete\n");
    scanf("%d",&p);
    delete_at_pos(&head,p);
    
    m=count(&head);
    display3(&head,m);
    delete_list(&head); // last step;
}