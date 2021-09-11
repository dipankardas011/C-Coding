/*XOR Linked List – A Memory Efficient Doubly Linked List | Set 1
Now there is a memory-efficient version of Doubly Linked List that can be 
created using only one space for the address field with every node. 
This memory efficient Doubly Linked List is called XOR Linked List 
or Memory Efficient as the list uses bitwise XOR 
operation to save space for one address. In the XOR linked list, 
instead of storing actual memory addresses, every node 
stores the XOR of addresses of previous and next nodes. 

For example: When we are at node C, we must have the address of B. XOR of add(B) and npx of C gives us the add(D).

Illustration:

Node A: 
npx = 0 XOR add(B) // bitwise XOR of zero and address of B 

Node B: 
npx = add(A) XOR add(C) // bitwise XOR of address of A and address of C 

Node C: 
npx = add(B) XOR add(D) // bitwise XOR of address of B and address of D 

Node D: 
npx = add(C) XOR 0 // bitwise XOR of address of C and 0 
npx(C) XOR add(B) 
=> (add(B) XOR add(D)) XOR add(B) // npx(C) = add(B) XOR add(D)
=> add(B) XOR add(D) XOR add(B) // a^b = b^a and (a^b)^c = a^(b^c)
=> add(D) XOR 0  // a^a = 0
=> add(D)     // a^0 = a
*/
#include <bits/stdc++.h>
#include <cinttypes>

using namespace std;

class node{
    public:
    int data;
    node* xpr;
};

// method 1
node* Xor(node* x, node* y){
    return reinterpret_cast<node*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

// method 2
void insert(node** head_ref, int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->xpr=*head_ref;

    if(*head_ref!=NULL){
        // *(head_ref)->xpr is xor of (NULL and next)
        (*head_ref)->xpr=Xor(newnode, (*head_ref)->xpr);
    }
    *head_ref=newnode;
}

// method 3
void disp(node* root)
{
    node* curr=root;
    node* prev=NULL;
    node* next;

    cout<<"the nodes of linklist are: \n";
    while(curr){
        cout<<curr->data<<" ";

        next = Xor(prev, curr->xpr);
        prev=curr;
        curr=next;
    }
}

int main()
{
    node* head=0;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);

    disp(head);
    return 0;
}