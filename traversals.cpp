#include<bits/stdc++.h>
using namespace std;
// time and space complexity is given by O(n) for inorder ,preorder and for the postorder as well.

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
void iterativepreorder(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        auto temp=st.top();
        st.pop();
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
        cout<<temp->data<<" ";
    }
}
void inorder(Node* root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return ;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    iterativepreorder(root);
    cout<<endl;


    return 0;
}