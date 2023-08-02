#include<bits/stdc++.h>
using namespace std;

// time and space complexity of this particular algo is given by O(log(n)) for both

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


int findceil(Node* root ,int temp){
    int ceil=-1;
    while(root!=NULL){
        if(root->data==temp){
            ceil = root->data;
            return ceil;
        }
        if(temp>root->data){
            root=root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int main(){



    return 0;
}