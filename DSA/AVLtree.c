/*Insertion 
To make sure that the given tree remains AVL after every insertion, we must augment the standard BST insert operation to perform some re-balancing. Following are two basic operations that can be performed to re-balance a BST without violating the BST property (keys(left) < key(root) < keys(right)). 
1) Left Rotation 
2) Right Rotation

T1, T2 and T3 are subtrees of the tree 
rooted with y (on the left side) or x (on 
the right side)           
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the 
following order 
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.

Steps to follow for insertion 
Let the newly inserted node be w 
1) Perform standard BST insert for w. 
2) Starting from w, travel up and find the first unbalanced node. 
Let z be the first unbalanced node, y be the child of z that comes 
on the path from w to z and w be the grandchild of z that comes on the path from w to z. 
3) Re-balance the tree by performing appropriate rotations on the subtree rooted with z. 
There can be 4 possible cases that needs to be handled as x, y and z can be arranged in 4 ways. Following are the possible 4 arrangements: 
a) y is left child of z and x is left child of y (Left Left Case) 
b) y is left child of z and x is right child of y (Left Right Case) 
c) y is right child of z and x is right child of y (Right Right Case) 
d) y is right child of z and x is left child of y (Right Left Case)
Following are the operations to be performed in above mentioned 4 cases. In all of the cases, we only need to 
re-balance the subtree rooted with z and the complete tree becomes balanced as the height of subtree 
(After appropriate rotations) rooted with z becomes same as it was before insertion. (See this video lecture for proof)


z can be arranged in 4 ways. Following are the possible 4 arrangements: 
a) y is left child of z and x is left child of y (Left Left Case) 
b) y is left child of z and x is right child of y (Left Right Case) 
c) y is right child of z and x is right child of y (Right Right Case) 
d) y is right child of z and x is left child of y (Right Left Case)

a) Left Left Case 

T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
b) Left Right Case 

     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
c) Right Right Case 

  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(z)       z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4
d) Right Left Case 

   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
  
1) Perform the normal BST insertion. 
2) The current node must be one of the ancestors of the newly inserted node. Update the height of the current node. 
3) Get the balance factor (left subtree height – right subtree height) of the current node. 
4) If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or left Right case. To check whether it is left left case or not, compare the newly inserted key with the key in left subtree root. 
5) If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right-Left case. To check whether it is Right Right case or not, compare the newly inserted key with the key in right subtree root. 

*/

#include <stdio.h>
#include <stdlib.h>

struct avltree{
  int data;
  struct avltree *left, *right;
  int height;
};
// calculates the balancing factor
int height(struct avltree *N){
  if(N==0)  return 0;
  return N->height;
}
int maxg(int a, int b){
  return (a>b)? a:b;
}

struct avltree *create(int data){
  struct avltree *t=(struct avltree *)malloc(sizeof(struct avltree));
  t->data=data;
  t->left=t->right=0;
  t->height=1;

  return t;
}

int getBalance(struct avltree *N){
  if(N==0)  return 0;
  return height(N->left)-height(N->right);
}

struct avltree *RightRotate(struct avltree *y){
  struct avltree *x=y->left;
  struct avltree *t2=x->right;

  x->right=y;
  y->left=t2;

  y->height=maxg(height(y->left),height(y->right))+1;
  x->height=maxg(height(x->left), height(x->right))+1;

  return x;
}


struct avltree *LeftRotate(struct avltree *x){
  struct avltree *y=x->right;
  struct avltree *t3=x->left;

  y->left=x;
  x->right=t3;

  // height of x and y changed
  x->height=maxg(height(x->left), height(x->right))+1;
  y->height=maxg(height(y->left), height(y->right))+1;
  return y;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
struct avltree *insert(struct avltree *node, int kkk){
  if(node==0) return create(kkk);

  if(kkk<node->data)
    node->left=insert(node->left,kkk);
  
  else if(kkk>node->data)
    node->right=insert(node->right, kkk);
  else
    return node;
  // till here the BST created
  // then we have to balance
  node->height = maxg(height(node->left), height(node->right)) + 1;
  int balance=getBalance(node);
  // if unbalanced
  // left-left unbalanced
  if (balance > 1 && kkk < node->left->data)
    return RightRotate(node);
  
  //right-right unbalanced
  if (balance < -1 && kkk > node->right->data)
    return LeftRotate(node);

  //left-right unbalanced
  if(balance > 1 && kkk>node->left->data){
    node->left=LeftRotate(node->left);
    return RightRotate(node);
  }

  //right-left unbalanced
  if(balance <-1 && kkk<node->right->data){
    node->right=RightRotate(node->right);
    return LeftRotate(node);
  }

  // unchanged pointer
  return node;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void preorder(struct avltree *t){
  if(t){
    printf("%d ",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}

void delete(struct avltree *p){
    struct avltree *templ,*tempr;
    if(p!=NULL){
        templ=p->left;
        tempr=p->right;
        printf("DELETE\n");
        free(p);
        delete(templ);
        delete(tempr);
    }
}

/*Unlike insertion, in deletion, after we perform a rotation at z, 
we may have to perform a rotation at ancestors of z. 
Thus, we must continue to trace the path until we reach the root.*/
/*The following C implementation uses the recursive BST delete as basis. In the recursive BST delete, after deletion, we get pointers to all ancestors one by one in bottom up manner. So we don’t need parent pointer to travel up. The recursive code itself travels up and visits all the ancestors of the deleted node.
1) Perform the normal BST deletion.
2) The current node must be one of the ancestors of the deleted node. Update the height of the current node.
3) Get the balance factor (left subtree height – right subtree height) of the current node.
4) If balance factor is greater than 1, then the current node is unbalanced and we are either in Left Left case or Left Right case. To check whether it is Left Left case or Left Right case, get the balance factor of left subtree. If balance factor of the left subtree is greater than or equal to 0, then it is Left Left case, else Left Right case.
5) If balance factor is less than -1, then the current node is unbalanced and we are either in Right Right case or Right Left case. To check whether it is Right Right case or Right Left case, get the balance factor of right subtree. If the balance factor of the right subtree is smaller than or equal to 0, then it is Right Right case, else Right Left case.
*/
struct avltree *minValue(struct avltree *node){
  struct avltree *curr=node;
  while(curr->left)
    curr=curr->left;
  
  return curr;
}

struct avltree *deleteavlnode(struct avltree *root, int key){
  // BST delete
  if(root==0) return root;

  if (key < root->data)
    root->left=deleteavlnode(root->left,key);
  else if(key> root->data)
    root->right=deleteavlnode(root->right,key);
  
  else{
    //found
    // one child or no child
    if( (root->left==0) || (root->right==0)){
      //storing the child
      struct avltree *temp=root->left? root->left : root->right;
      // no child
      if(temp==0){
        temp=root;
        root=NULL;
      }
      else
        *root=*temp;// copy the contents of child
      free(temp);
    }
    else{
      // 2 childrens
      //inorder successor (smallest in right sub-tree)
      struct avltree *temp=minValue(root->right);
      root->data=temp->data;
      //delete the inorder succesor
      root->right=deleteavlnode(root->right, temp->data);
    }
  }

  // now balancing
  if(root==NULL)  return root;

  root->height=1+maxg(height(root->left), height(root->right));
  int balance=getBalance(root);

  // left-left unbalanced
  if(balance>1 && getBalance(root->left)>=0)
    return RightRotate(root);
  // left-right unbalanced
  if(balance>1 && getBalance(root->left)<=0){
    root->left=LeftRotate(root->left);
    return RightRotate(root);
  }

  // right-right unbalanced
  if(balance <-1 && getBalance(root->right)<=0)
    return LeftRotate(root);
  // right-left unbalanced
  if(balance <-1 && getBalance(root->right)>=0){
    root->right=RightRotate(root->right);
    return LeftRotate(root);
  }

  return root;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* The constructed AVL Tree would be 
            9 
           /  \ 
          1    10 
        /  \     \ 
       0    5     11 
      /    /  \ 
     -1   2    6 
    */
/* The AVL Tree after deletion of 10 
            1 
           /  \ 
          0    9 
        /     /  \ 
       -1    5     11 
           /  \ 
          2    6 
    */
int main(){
  struct avltree *root=0;
  root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2);
  printf("preorder traversal: ");
  preorder(root);
  printf("\n");
  root=deleteavlnode(root, 10);
  printf("preorder traversal: ");
  preorder(root);
  printf("\n");


  int g;
  struct avltree *root1=0;
  do{
    printf("\nenter the element: ");
    scanf("%d",&g);
    root1 = insert(root1,g);
    printf("enter y to continue... ");
    while ((getchar()) != '\n'); // clean the input buffer
  }while(getchar()=='y');
  preorder(root1);
  printf("\n");
  delete(root);
  delete(root1);
}