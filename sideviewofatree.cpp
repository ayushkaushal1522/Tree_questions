#include<bits/stdc++.h>
using namespace std;

// time complexity is given by O(n)
// while space complexity is given by O(H) 
// where H is the height of the binary tree.

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

void func1(Node* root , int level , vector<int> &res){
    if(root==NULL) return;
    if(level==res.size()) res.push_back(root->data);
    func1(root->right,level+1,res);
    func1(root->left,level+1,res);
}

void func2(Node* root , int level , vector<int> &res){
    if(root==NULL) return;
    if(level==res.size()) res.push_back(root->data);
    func2(root->left,level+1,res);
    func2(root->right,level+1,res);
    
}


vector<int> rightviewofatree(Node* root){
    vector<int> res;
    func1(root,0,res);
    return res;
}
vector<int> leftviewofatree(Node* root){
    vector<int> res;
    func2(root,0,res);
    return res;
}



int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    // root->right->left=new Node(4);
    root->right->right=new Node(7);

    // root->left->left->left=new Node(8);
    // root->left->left->right=new Node(9);
    

    root->left->right->left = new Node(6);
    // root->left->right->right = new Node(11);
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    vector<int> res = rightviewofatree(root);
    vector<int> ans = leftviewofatree(root);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;


    return 0;
}