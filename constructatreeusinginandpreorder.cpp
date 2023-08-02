//we can definately make a tree using the preorder and post order traversal but for making the unique 
//binary tree it ismust that we have inorder traversal array with us.
#include<bits/stdc++.h>
using namespace std;

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
Node* buildtree(vector<int> &preorder , int prestart , int preend , vector<int> &inorder ,int instart ,int inend , map<int,int> mp){
    if(prestart>preend || instart>inend) return NULL;
    Node* root = new Node(preorder[prestart]);
    int inroot = mp[root->data];

    int numsleft = inroot -instart;

    root->left = buildtree(preorder , prestart + 1 , prestart+numsleft ,inorder ,instart , inroot-1 ,mp);
    root ->right =buildtree(preorder , prestart+numsleft+1 , preend ,inorder ,inroot +1 ,inend ,mp);

    return root;

 }

Node* maketree(vector<int> &preorder , vector<int> &inorder){
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;

    }

    Node* root = buildtree(preorder , 0 ,preorder.size()-1,inorder ,0 ,inorder.size()-1 ,mp);
    return root;
 }

 
int main(){












    return 0;
}