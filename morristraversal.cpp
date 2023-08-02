#include<bits/stdc++.h>
using namespace std;

//this travel is same as that of the preorder traversal 
//time complexity for this particular algo is O(n).
//while space complexity is given by O(1) because leaving the space consume by the ans vector 
// it is not consuming any space really.

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

vector<int> morristraversal(Node* root) {
       vector<int> ans;
       Node* curr = root;
       while(curr!=NULL){
           if(curr->left==NULL){
               ans.push_back(curr->data);
               curr=curr->right;
           } 
           else{
               Node* node = curr->left;
               while(node->right!=NULL && node->right !=curr){
                   node=node->right;
               }
               if(node->right==NULL){
                   node->right = curr;
                   ans.push_back(curr->data);
                   curr=curr->left;
               }
               else{
                   node->right=NULL;
                   curr=curr->right;
               }
           }
       }
       return ans;
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


    vector<int> ans=morristraversal(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    inorder(root);

    return 0;
}