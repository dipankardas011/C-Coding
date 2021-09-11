#include <stdio.h>
#include <stdlib.h>

typedef struct pri_que{
    int data;
    int priority;
    struct pri_que *next;
}que;

que *front=NULL, *rear=NULL;

void input(int val, int priority){
    que *temp=(que *)malloc(sizeof(que));
    if(!temp){
        printf("~~~ MEMORY ERROR ~~~\n");
        return ;
    }
    temp->data=val;
    temp->priority=priority;
    temp->next=NULL;

    if(rear==NULL){
        rear=temp;
        front=rear;
    }
    else{
        if(front->priority < priority){
            /* it the priority is more than the front then it should be before the front */
            temp->next=front;
            front=temp;
        }
        
        else if(rear->priority >priority){
            /* if the prority is less than the rear then it should be after the rear*/
            rear->next=temp;
            rear=temp;
        }
        
        else{
            que *ptr=front;
            /*the position*/
            while(ptr->next->priority>=priority)
                //means the front.next proority is > than priority
                ptr=ptr->next;
            
            temp->next=ptr->next;
            ptr->next=temp;
        }
    }
}

void pop(int *value, int *priority){
    que *temp;
    if(front==rear && rear==NULL){
        *value=*priority=INT_MIN;
        return ;
    }
    *value=front->data;
    *priority=front->priority;
    temp=front;
    front=front->next;

    if(rear=temp)
        rear=rear->next;
    free(temp);
}

void display(){

    if(front==rear && rear==NULL){
        printf("^~~~~~ EMPTY QUEUE\n");
        return;
    }
    que *f=front;
    printf("\n\nDATA\tPRIORITY\tNEXT\n");
    while(f!=rear){
        printf("%d\t%d\t\t%u\n",f->data,f->priority,f->next);
        f=f->next;
    }
    printf("%d\t%d\t\t%u\n",f->data,f->priority,f->next);
    free(f);
}

void delete(){
    que *t;
    while(front!=rear){
        t=front;
        free(front);
        t=t->next;
        front=t;
    }free(t);
}

int main(){
    system("cls");
    printf("\nWELCOME TO PRIORITY QUEUE\n");
    int x,p;
    int m;
    do{
        printf("enter 1 to input, 2 to pop, 3 to display\n");
        scanf("%d",&m);
        switch(m){
            
            case 1:printf("enter the value and the priority\n");
            scanf("%d%d",&x,&p);
            input(x,p);
            break;
            
            case 2:pop(&x,&p);
            if(x==INT_MIN && p==INT_MIN)printf("^~~~ empty queue\n");
            else printf("the poped element value: %d, priority: %d\n",x,p);
            break;
            
            case 3: display();
            break;

            default: printf("^~~~~ WRONG KEY PRESSED\n");
        }
        printf("\tENTER 1 TO CONTINUE\n");
        scanf("%d",&m);
    }while(m==1);
    delete();
    return 0;
}