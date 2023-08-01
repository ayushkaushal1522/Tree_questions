#include<bits/stdc++.h>
using namespace std;

// this algo will be applicable only when there is no duplicate 
// numbers as it gets failed due to the multile retuen statements .

// time coplexity is given by O(n).
// space complexity is also given by O(n) only .


class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }    
};

Node* lca(Node* root , Node* temp1 , Node* temp2){
    if(root==NULL) return NULL;
    if(root==temp1) return root;
    if(root==temp2) return root;

    Node* left = lca(root->left , temp1 ,temp2);
    Node* right = lca(root->right , temp1 , temp2);

    if(left==NULL) return right;
    else if(right==NULL) return left;
    else return root;
}

int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    auto ans =lca(root,root->right->left->left,root->right->right->right);

    cout<<ans->data<<endl;
    return 0;
}