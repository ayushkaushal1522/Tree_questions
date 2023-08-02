#include<bits/stdc++.h>
using namespace std;

// as we are just traversing along the geight of the binary tree so the 
// time complexity is given by O(log(n)) only.


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

Node* insertintobst(Node* root , int value){
    if(root==NULL) return new Node(value);
    Node* curr = root;
    while(true){
        if(curr->data<=value){
            if(curr->right !=NULL)  curr=curr->right;
            else{
                curr->right = new Node(value);
                break;
            }
           
        }
        else{
            if(curr->left!=NULL) curr=curr->left;
            else{
                curr->left = new Node(value);
                break;
            }
        }
        
    }
    return root;
}

int main(){


    return 0;
}