#include<bits/stdc++.h>
using namespace std;

// time complexity is given by O(n).
// space complexity is also given by O(n) only.

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

bool func(Node* root , int x , vector<int> &res){
    if(root==NULL) return false;
    res.push_back(root->data);
    if(root->data==x) return true;
    if(func(root->left,x,res)) return true;
    if(func(root->right , x,res)) return true;
    res.pop_back();
    return false;

    
}


vector<int> getpath(Node* root ,int x){
    vector<int> res;
    if(root==NULL) return res;
    func(root,x,res);
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
    
    vector<int> res = getpath(root,15);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;


    return 0;
}