#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct btree{
    char data;
    struct btree *left, *right;
}tree;

tree *create_memory(){
    tree *t;
    t=(tree *)malloc(sizeof(tree));
    t->left=t->right=NULL;

    return t;
}

void input(tree **root){
    tree *t=*root, *new_node;
    int m=0,ch;
    int cond;
    if(t==NULL){
        t=create_memory();
        //printf("%u\n",t);
        printf("enter the root element\n");
        scanf(" %c",&t->data);
        //printf("\t\t%c\n",t->data); // printing the parent node
        *root=t;
    }
    do{
        new_node=create_memory();
        //printf("%u\n",new_node);
        printf("enter the element\n");
        scanf(" %c",&new_node->data);
        cond=0;
        ch=0;
        t=*root;
        while(cond==0){
            printf("To insert in LEFT ENTER 1 and 2 FOR RIGHT\n");
            scanf("%d",&ch);
            printf("\t\tECHO: %d\n",ch);
            switch(ch){
                case 1:
                    //left operation
                    if(t->left == NULL){
                        t->left=new_node;
                        cond=1;
                        //printf("\t\t%c\n",t->data); // printing the parent node
                    }
                    else{
                        t=t->left;
                        cond=0;
                    }
                break;
                case 2:
                    //right operation
                    if(t->right == NULL){
                        t->right=new_node;
                        cond=1;
                        //printf("\t\t%c\n",t->data); // printing the parent node
                    }
                    else{
                        t=t->right;
                        cond=0;
                    }
                break;
                default:printf("overflow with: %d\n",ch);
            }
        }
        
        printf("\tenter 1 to continue\n");
        scanf("%d",&m);
    }while(m==1);
}

void inorder_dis(tree *p){ // left root right
    if(p!=NULL){
        inorder_dis(p->left);
        printf("%c\t",p->data);
        inorder_dis(p->right);
    }
}

void preorder_dis(tree *p){ // root left right
    if(p!=NULL){
        printf("%c\t",p->data);
        preorder_dis(p->left);
        preorder_dis(p->right);
    }
}

void postorder_dis(tree *p){ // left right root
    if(p!=NULL){
        postorder_dis(p->left);
        postorder_dis(p->right);
        printf("%c\t",p->data);
    }
}

int levels(tree *root){
    if(root==NULL)
        return 0;
    int l_height=levels(root->left);
    int r_height=levels(root->right);
    return fmax(l_height,r_height)+1;
}

void printlevel(tree *root, int l){
    if(root==NULL){
        printf("# ");
        return;
    }
    if(l==1)
        printf("%c  ",root->data);
    else if(l>1){
        printlevel(root->left,l-1);
        printlevel(root->right,l-1);
    }
}

void display(tree *root){
    int h=levels(root);
    int i;
    for(i=1;i<=h;i++){
        for(int j=i;j<=h;j++)
            printf("  ");
        printlevel(root,i);
        printf("\n\n");
    }
}

void delete(tree *p){
    tree *templ,*tempr;
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
    printf("\nWELCOME TO BINARY TREE\n");
    tree *root=NULL;
    input(&root);
    printf("\nINORDER TRAVERSAL\n");
    inorder_dis(root);
    printf("\nPREORDER TRAVERSAL\n");
    preorder_dis(root);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder_dis(root);
    printf("\n");
    printf("\n");
    display(root);

    delete(root);
}