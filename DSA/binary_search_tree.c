#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

typedef struct binary_tree{
    int data;
    struct binary_tree *left, *right;
}btree;

btree *create_memory(){
    btree *t;
    t=(btree *)malloc(sizeof(btree));
    if(!t){
        printf("memory allocation ERROR!\n");
        exit(0);
    }
    t->left = t->right = NULL;

    return t;
}

btree * strict_binary_input(btree *p, int val){
    btree *temp1, *temp2;
    if(p==NULL){
        p=create_memory();
        (p)->data=val;
    }
    else{
        temp1=p;
        while(temp1!=NULL){
            temp2=temp1;
            if(temp1->data > val)
                temp1=temp1->left;
            else
                temp1=temp1->right;
        }
        if(temp2->data>val){
            temp2->left=create_memory();
            temp2=temp2->left;
            temp2->data=val;
        }
        else{
            temp2->right=create_memory();
            temp2=temp2->right;
            temp2->data=val;
        }
    }
    return p;
}


int levels(btree *root){
    if(root==NULL)
        return 0;
    int l_height=levels(root->left);
    int r_height=levels(root->right);
    return fmax(l_height,r_height)+1;
}

void printlevel(btree *root, int l){
    if(root==NULL){
        printf("#  ");
        return;
    }
    if(l==1)
        printf("%d  ",root->data);
    else if(l>1){
        printlevel(root->left,l-1);
        printlevel(root->right,l-1);
    }
}

void display(btree *root){
    int h=levels(root);
    int i;
    for(i=1;i<=h;i++){
        for(int j=i;j<=h;j++)
            printf("  ");
        printlevel(root,i);
        printf("\n\n");
    }
}

btree *search(btree *p, int key){
/* only happens where the data is arranged in left < root < right */
    btree *temp=p;
    while(temp!=NULL){
        if(temp->data==key)
            return temp;
        else if(temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

void delete(btree *p){
    btree *templ,*tempr;
    if(p!=NULL){
        templ=p->left;
        tempr=p->right;
        free(p);
        delete(templ);
        printf("DELETE");
        delete(tempr);
    }
}


int main(){
    system("cls");
    printf("welcome to the bianry tree\n");
    btree *root=NULL;
    int m;
    do{
        printf("enter element to be inserted\n");
        scanf("%d",&m);
        root=strict_binary_input(root,m);
        printf("ENTER 1 TO CONTINUE\n");
        scanf("%d",&m);
    }while(m==1);
    display(root);

    printf("enter the value to be searched\n");
    scanf("%d",&m);
    btree *s = search(root,m);
    if(!s)
        printf("NOT FOUND\n");
    else
        printf("FOUND: %d\n",s->data);
    delete(root);
}