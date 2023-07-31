#include<bits/stdc++.h>
using namespace std;

// time and space complexity is given by o(n) for both of them.

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



int heightofatree(Node* root){
    if(root==NULL) return 0;
    int l=heightofatree(root->left);
    int r=heightofatree(root->right);
    return 1+max(l,r);
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
    int height = heightofatree(root);
    cout<<height<<endl;


    return 0;
}