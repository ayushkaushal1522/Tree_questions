#include<bits/stdc++.h>
using namespace std;

// time and space complexity of this particular algo is given by O(n) for both

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



vector<vector<int>> zigzagtraversal(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    bool flag=false;
    while(!q.empty()){
        int n=q.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            auto it =q.front();
            q.pop();
            temp.push_back(it->data);
            if(it->left!=NULL) q.push(it->left);
            if(it->right!=NULL) q.push(it->right);
        }
        if(flag==true){
            reverse(temp.begin(),temp.end());
        }
        flag=!flag;
        ans.push_back(temp);

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

    vector<vector<int>> res=zigzagtraversal(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}