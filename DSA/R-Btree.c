/*Rules That Every Red-Black Tree Follows: 
1. Every node has a colour either red or black.
2. The root of the tree is always black.
3. There are no two adjacent red nodes (A red node cannot have a red parent or red child).
4. Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.

Interesting points about Red-Black Tree:
1. Black height of the red-black tree is the number of black nodes on a path from the root node to a leaf node. Leaf nodes are also counted as black nodes. So, a red-black tree of height h has black height >= h/2.
2. Height of a red-black tree with n nodes is h<= 2 log2(n + 1).
3. All leaves (NIL) are black.
4. The black depth of a node is defined as the number of black nodes from the root to that node i.e the number of black ancestors.
5. Every red-black tree is a special case of a binary tree.

Black Height of a Red-Black Tree : 
Black height is the number of black nodes on a path from the root to a leaf. 
Leaf nodes are also counted black nodes. From the above properties 3 and 4, we can derive, a Red-Black Tree of height h has black-height >= h/2. 
Number of nodes from a node to its farthest descendant leaf is no more than twice as the number of nodes to the nearest descendant leaf.

Every Red Black Tree with n nodes has height <= 2Log2(n+1) 
This can be proved using the following facts:

1. For a general Binary Tree, let k be the minimum number of nodes on all root to NULL paths, then n >= 2k – 1 (Ex. If k is 3, then n is at least 7). This expression can also be written as k <= Log2(n+1).
2. From property 4 of Red-Black trees and above claim, we can say in a Red-Black Tree with n nodes, there is a root to leaf path with at-most Log2(n+1) black nodes.
3. From property 3 of Red-Black trees, we can claim that the number of black nodes in a Red-Black tree is at least ⌊ n/2 ⌋ where n is the total number of nodes.
From the above points, we can conclude the fact that Red Black Tree with n nodes has height <= 2Log2(n+1)
*/

// First, you have to insert the node similarly to that in a binary tree and
// assign a red colour to it. Now, if the node is a root node then
// change its colour to black, but if it does not then check the colour
// of the parent node. If its colour is black then don’t change the colour
// but if it is not i.e. it is red then check the colour of the node’s uncle.
// If the node’s uncle has a red colour then change the colour of the node’s
// parent and uncle to black and that of grandfather to red colour and
// repeat the same process for him (i.e. grandfather).
// But, if the node’s uncle has black colour then there are 4 possible cases:
// left left case(right rotation og grandfather of node; then swap the colours of grandfather and parent)
// left right case (left rotation of parent; then ll rotation case)
// right right case (left rotation of grandparent; swap the colours of grandparent and parent)
// right left case (right rotate parent; now apply RR rotation case)

// Algorithm:
// Let x be the newly inserted node.

// Perform standard BST insertion and make the colour of newly inserted nodes as RED.
// If x is the root, change the colour of x as BLACK (Black height of complete tree increases by 1).
// Do the following if the color of x’s parent is not BLACK and x is not the root.
// a) If x’s uncle is RED (Grandparent must have been black from property 4)
// (i) Change the colour of parent and uncle as BLACK.
// (ii) Colour of a grandparent as RED.
// (iii) Change x = x’s grandparent, repeat steps 2 and 3 for new x.
// b) If x’s uncle is BLACK, then there can be four configurations for x, x’s parent (p) and x’s grandparent (g) (This is similar to AVL Tree)
// (i) Left Left Case (p is left child of g and x is left child of p)
// (ii) Left Right Case (p is left child of g and x is the right child of p)
// (iii) Right Right Case (Mirror of case i)
// (iv) Right Left Case (Mirror of case ii)

// Example: Creating a red-black tree with elements 3, 21, 32 and 17 in an empty tree.
#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int data;  // data
    int color; // 1-red, 0 black
    struct btree *parent;
    struct btree *left;
    struct btree *right;
};
struct btree *root = NULL;

struct btree *create(int val)
{
    struct btree *t = (struct btree *)malloc(sizeof(struct btree));
    t->data = val;
    t->left = t->right = t->parent = 0;
    t->color = 1;
    return t;
}
//bst insertion
struct btree *insert1(struct btree *trav, struct btree *temp)
{
    if (trav == NULL)
        return temp;

    if (temp->data < trav->data)
    {
        trav->left = insert1(trav->left, temp);
        trav->left->parent = trav;
    }
    else if (temp->data > trav->data)
    {
        trav->right = insert1(trav->right, temp);
        trav->right->parent = trav;
    }
    //return unchanged node
    return trav;
}

void RightRotate(struct btree *temp)
{
    struct btree *left = temp->left;
    temp->left = left->right;
    if (temp->left)
        temp->left->parent = temp;
    left->parent = temp->parent;
    if (!temp->parent)
        root = left; // root condition
    else if (temp == temp->parent->left)
        temp->parent->left=left;
    else    temp->parent->right=left;

    left->right=temp;
    temp->parent=left;
}

void LeftRotate(struct btree *temp){
    struct btree *right=temp->right;
    temp->right=right->left;
    if(temp->right)// if exist
        temp->right->parent=temp;
    
    right->parent=temp->parent;

    if(!temp->parent) // root
        root=right;
    else if(temp==temp->parent->right)
        temp->parent->right=right;
    else
        temp->parent->left=right;
    right->left=temp;
    temp->parent=right;
}
//it fix's
void insert2(struct btree *root,struct btree *pt){
    struct btree *parent=NULL;
    struct btree *grandparent=NULL;

    while((pt!=root) && (pt->color!=0) &&(pt->parent->color == 1)){
        // not a root, must be red, parent must be red
        parent=pt->parent;
        grandparent=pt->parent->parent;
        // if parent is left child grandparent
        if(parent==grandparent->left)
        {
            struct btree *uncle=grandparent->right;
            if(uncle!=NULL && uncle->color==1)// red
            {
                grandparent->color=1;
                parent->color=uncle->color=0;//black
                pt=grandparent;
            }
            else
            {
                // uncle is black
                if(pt==parent->right){
                    LeftRotate(parent);
                    pt=parent;
                    parent=pt->parent;// grandparent
                }
                //left child
                RightRotate(grandparent);

                int t=parent->color;
                parent->color=grandparent->color;
                grandparent->color=t;
                pt=parent;
            }
        }
        else{
            // right child of grandparent
            struct btree *uncle=grandparent->left;
            if(uncle!=NULL && uncle->color==1){
                grandparent->color=1;
                parent->color=uncle->color=0;//black
                pt=grandparent;
            }
            else{
                //uncle is black
                if(pt==parent->left){
                    RightRotate(parent);
                    pt=parent;
                    parent=pt->parent;
                }
                LeftRotate(grandparent);
                int t=parent->color;
                parent->color=grandparent->color;
                grandparent->color=t;

                pt=parent;
            }
        }
    }

    root->color=0;
}

void inorder(struct btree *k){
    if(k==NULL) return;

    inorder(k->left);
    printf("%d ",k->data);
    inorder(k->right);
}


int main()
{
    int ff;
    do{
        printf("enter the data = ");
        scanf("%d",&ff);
        struct btree *new = create(ff);
        root=insert1(root,new);
        insert2(root,new);
        printf("enter 'y' to continue... ");
        while ((getchar()) != '\n');
    }while(getchar()=='y');

    printf("inorder: ");
    inorder(root);
    return 0;
}