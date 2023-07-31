//balance binary tree is a tree which has leftHeight - rightHeight<=1;
#include<bits/stdc++.h>
using namespace std;
// time and space complexity for the dine approach is O(n) both.

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
    if(l==-1) return -1;
    int r=heightofatree(root->right);
    if(r==-1) return -1;
    if(abs(l-r)>1) return -1;
    return 1+max(l,r);
} 

bool isbalanced(Node* root){

    return  heightofatree(root)!=-1;
}



int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<isbalanced(root)<<endl;


    return 0;
}