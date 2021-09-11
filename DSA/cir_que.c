/*
    CIRCULAR QUEUE USING ARRAY
*/

#include <stdio.h>
#define size 5

int dque[size];
int f=-1,r=-1;

void enqueue(int x){
    if((r+1)%size == f)
        printf("queue is full\n");
    else{
        if(r==f && f==-1)
            f+=1;
        r=(r+1)%size;
        dque[r]=x;
    }
}

void dequeue(){
    if(r==f && r==-1)
        printf("queue is empty\n");
    else{
        int i=dque[f];
        if(r==f)
            f=r=-1;
        else
            f=(f+1)%size;
        printf("element removed :%d\n",i);
    }
}

void display(){
    int tmpf=f;
    if(r==f && r==-1)
        printf("queue is empty\n");
    else{
        printf("the elements: \n");
        for(int i=0;i<size;i++){
            if(tmpf!=r){
                printf("%d\n",dque[tmpf]);
                tmpf=(tmpf+1)%size;
            }
            else{
                printf("%d\n",dque[r]);
                break;
            }
        }
    }
}

int main(){
    printf("welcome to circular queue in array implementation\n\n");
    int x;
    while(1){
        printf("enter 1 to input element, 2 to dequeue, 3 to display and 4 to exit\n");
        scanf("%d",&x);
        switch(x){
            case 1:printf("enter the number: ");scanf("%d",&x);enqueue(x);
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            
            case 4:return 0;
        }
    }
}