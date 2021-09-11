// splay tree insertion
#include <bits/stdc++.h>

class node{
    public:
    int data;
    node *left, *right;
};

node *newNode(int key){
    node *t=new node();
    t->data=key;
    t->left=t->right=NULL;
    return t;
}

node *RightRotate(node *r){
    node *left=r->left;
    r->left=left->right;
    left->right=r;
    return left;
}

node *LeftRotate(node *x){
    node *right=x->right;
    x->right=right->left;
    right->left=x;
    return right;
}
// brings last inserted item to root
// if not present then brings the last accessed item
// at root.
node *splay(node *root,int key){
    if(root==NULL || root->data==key)
        return root;
    
    if(root->data > key){
        // left subtree
        if(root->left==NULL)    return root;
        // zig-zig (left-left)
        if(root->left->data > key){
            root->left->left=splay(root->left->left, key);
            root=RightRotate(root);
        }
        else if(root->left->data < key){// zig-zag (left right)
            root->left->right=splay(root->left->right,key);
            if(root->left->right!=NULL)
                root->left=LeftRotate(root->left);
        }
        // do second rotation
        return (root->left==NULL)?root:RightRotate(root);
    }
    
    else{
        //right subtree
        if(root->right==NULL)   return root;
        //zig-zag (right-left)
        if(root->right->data > key){
            root->right->left=splay(root->right->left,key);
            if(root->right->left!=NULL)
                root->right=RightRotate(root->right);
        }
        else if(root->right->data < key)
        {
            root->right->right=splay(root->right->right,key);
            root=LeftRotate(root);
        }
        return (root->right==NULL)?root:LeftRotate(root);
    }
}

node *search(node *root, int key) 
{ 
    return splay(root, key); 
} 

node *insert(node *root, int k)
{
    // if tree is empty
    if(root==NULL)  return newNode(k);
    //bring the closest leaf node to root
    root=splay(root,k);
    // if key is already present, then return
    if(root->data==k)   return root;
    // otherwise allocate memory for new node
    node *t=newNode(k);
    // root's key is greater, make
    // root as right child of newnode
    // copy the left child of root to newnode
    if(root->data > k){
        t->right=root;
        t->left=root->left;
        root->left=NULL;
    }
    //root key is smaller
    else{
        t->left=root;
        t->right=root->right;
        root->right=NULL;
    }
    return t;
}

void preorder(node *root){
    if(root!=NULL){
        std::cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    node *root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);
    root = insert(root, 25);
    std::cout<<"Preorder traversal of the modified Splay tree is \n";
    preorder(root);

    root = search(root, 20); 
    std::cout << "Preorder traversal of the modified Splay tree is \n"; 
    preorder(root);
    return 0;
}