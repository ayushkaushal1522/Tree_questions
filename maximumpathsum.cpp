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
int func(Node* root , int &ans){
    if(root==NULL) return 0;
    int l=max(0,func(root->left,ans));
    int r=max(0,func(root->right,ans));
    ans=max(ans,root->data+l+r);
    return root->data+max(l,r);
}

int maxpathsum(Node* root){
    int ans=INT_MIN;
    func(root,ans);
    return ans;

}



int main(){


    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    // root->left->left->left=new Node(8);
    // root->left->left->right=new Node(9);
    // root->left->right->left =new Node(10);
    // root->left->right->right = new Node(11);
    int maximumsum= maxpathsum(root);
    cout<<maximumsum<<endl;


    return 0;
}