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

int func(Node* root , int &dia){
    if(root==NULL) return 0;
    int l = func(root->left,dia);
    int r = func(root->right,dia);
    dia=max(dia,l+r);
    return 1+max(l,r);
}

int diameter(Node* root){
    int dia=0;
    func(root,dia);
    return dia;
}




int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<diameter(root)<<endl;

    


    return 0;
}