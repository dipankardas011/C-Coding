#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree *left, *right;
};

tree *NewNode(int key){
    tree *t=new tree;
    t->data=key;
    t->left=t->right=0;

    return t;
}
int maxlen = 0;

void leftView(tree *r, int level){
    if(!r)  return ;

    if(maxlen < level){
        cout<<r->data<<" ";
        maxlen = level;
    }

    leftView(r->left, level+1);
    leftView(r->right, level+1);
}



int main()
{
    tree *root = NULL;
    /*
        1
       / \
      2   3
           \
           6
    */
    root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->right->right = NewNode(6);
    // find the left view of the tree
    // here the o/p will be 1 2 6
    leftView(root, 1);
    return 0;
}