/* using array implementation*/

#include <stdio.h>
#define CAP 5

static int top=-1;
static int stack[CAP];

enum boolean{
    FALSE,
    TRUE
};

int is_empty(){
    if (top==-1)
        return TRUE;
    return FALSE;
}

void input(int x){
    if(top==CAP-1)
        printf("\nSTACK IS FULL!\n");
    else
        stack[++top]=x;
    return;
}

int pop(){
    int x;
    if(is_empty()==0)
        x=stack[top--];
    else
        x=-999;
    return x;
}

void display(){
    printf("\nelements in STACK\n");
    if(is_empty()==0){
        for(int i=top;i>=0;i--)
            printf("|%10d|\n",stack[i]);
    }
    else{
        printf("\nNO ELEMENTS ARE PRESENT\n");
    }
}

int main(){
    printf("\nWELCOME TO STACK (array implementation)\n");

    int ch;
    do{
        printf("\nenter 1 to push elements, 2 to pop elements, 3 to display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter element to be pushed: ");
            scanf("%d",&ch);
            input(ch);
            break;
            
            case 2:
            ch=pop();
            if(ch==-999) printf("\nNO elements left\n");
            else printf("elment removed: %d\n",ch);
            break;

            case 3:
            display();
            break;

            default: printf("INVALID input\n");
            return 0;
        }
        printf("\nenter 1 to continue\n");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}