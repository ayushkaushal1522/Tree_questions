#include<bits/stdc++.h>
using namespace std;

// 0 based indexing of the tree is given as 
// if i is the index of a particular node then 2*i+1 and 2*i+2 
// will be the index of its child.

// time ans space complexity will be given by o(n) for both of them at the worst case.


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

int widthofatree(Node* root){
    if(!root) return 0;
    int ans=0;
    queue<pair<Node* ,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int s= q.size();
        int temp=q.front().second;
        int first , last;
        for(int i=0;i<s;i++){
            int curr = q.front().second - temp;
            Node* node = q.front().first;
            q.pop();
            if(i==0) first = curr;
            if(i==s-1) last =curr;
            if(node->left) q.push({node->left,curr*2+1});
            if(node->right) q.push({node->right,curr*2+2}); 
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}

int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->right->left=new Node(6);
    root->right->right=new Node(7);
    // root->left->left->left=new Node(8);
    // root->left->left->right=new Node(9);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(11);
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    int ans= widthofatree(root);
    cout<<ans<<endl;


    return 0;
}