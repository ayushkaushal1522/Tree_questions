//To traverse the whole boundry break it into three parts which are the left
// boundry leaving the leaf nodes , then leaf nodes and then the irght boundry
#include<bits/stdc++.h>
using namespace std;

// Time complexity will be O(H)+O(H)+O(N) ~~ O(N).
//space coplexity will be O(N) which is the space required by the vector 
// to get stored.

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

bool isleaf(Node* root){
    if(root->left==NULL && root->right==NULL) return true;
    return false;
}
void leftbound(Node* root,vector<int> &res){
    Node* curr=root->left;
    while(curr)
    {
        if(!isleaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }

}
void rightbound(Node* root , vector<int> &res){
    Node* curr= root->right;
    vector<int> temp;
    while(curr){
        if(!isleaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
    
}

void leaves(Node* root,vector<int> &res){
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) leaves(root->left,res);
    if(root->right) leaves(root->right,res);
}

vector<int> printboundry(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isleaf(root)) res.push_back(root->data);
    leftbound(root,res);
    leaves(root,res);
    rightbound(root,res);
    return res;
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
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    
    vector<int> ans=printboundry(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}