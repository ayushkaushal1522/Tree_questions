//balance binary tree is a tree which has leftHeight - rightHeight<=1;
#include<bits/stdc++.h>
using namespace std;
//time complexity for this particular algo is O(n^2) as for each and evry node we are calculating the 
// left and the right height

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

bool check(Node* root){

    if(root==NULL) return true;

    int l=heightofatree(root->left);
    int r=heightofatree(root->right);
    if(abs(r-l)>1) return false;
    bool le=check(root->left);
    bool ri=check(root->right);
    if(!le || !ri) return false;
    return true;
}



int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    root->left->left->left=new Node(6);
    root->left->left->right=new Node(7);
    cout<<check(root)<<endl;


    return 0;
}