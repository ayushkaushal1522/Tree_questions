#include<bits/stdc++.h>
using namespace std;
// time and space complexity is given by O(n).

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

void iterativepostorder(Node* node){
    stack<Node*> st;
    Node* curr=node;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            Node* temp=st.top()->right;
            if(temp==NULL){
                Node* temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else curr=temp;
        }
    }
}

int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // vector<vector<int>> res=levelorder(root);
    // for(int i=0;i<res.size();i++){
    //     for(int j=0;j<res[i].size();j++){
    //         cout<<res[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    iterativepostorder(root);
    cout<<endl;


    return 0;
}