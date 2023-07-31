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

void iterativeinorder(Node* node){
    stack<Node*> st;
    Node* root=node;
    while(true){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        }
        else{
            if(st.empty()) break;
            root=st.top();
            st.pop();
            cout<<root->data<<" ";
            root=root->right;
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
    iterativeinorder(root);
    cout<<endl;


    return 0;
}