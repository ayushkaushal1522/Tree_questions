#include<bits/stdc++.h>
using namespace std;

// brute force to solve the problem is first find the inorder traversal 
// and then get the successor but this algo wil take time complexity of O(n)
// and space complexity of O(n) also.


// time complexity for this particular algo is given by O(h) ~~O(log(n)) which will be inturn equals to the 
// height of tehe tree.
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

Node* successor(Node* root ,Node* temp){
    Node* res = NULL;
    while(root!=NULL){
        if(temp->data>=root->data){
            root=root->right;
        }
        else{
            res=root;
            root=root->left;
        }
    }
    return res;
}

int main(){





    return 0;
}