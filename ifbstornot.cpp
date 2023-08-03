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

bool func(Node* root ,int mini , int maxi){
    if(root==NULL) return true;
    if(root->data>=maxi || root->data<=mini) return false;
    bool flag1 = func(root->left , mini , root->data);
    if(flag1==false) return false;
    bool flag2 = func(root->right , root->data , maxi);
    if(flag2==false) return false;
    return true;
}

bool isvalidbst(Node* root){
    return func(root , INT_MIN,INT_MAX);
}


int main(){
    return 0;
}
