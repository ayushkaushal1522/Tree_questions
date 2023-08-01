#include<bits/stdc++.h>
using namespace std;

// time complexity is given by O(n)
// space complexity is given by O(H)~~O(N) in the worst case.


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
vector<vector<int>> levelorder(Node* root){
    queue<Node*> q;
    vector<vector<int>> ans;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
        
       
    }
    return ans;
}
void childrensumprop(Node* root){
    if(root==NULL) return;
    int temp=0;
    if(root->left) temp+=root->left->data;
    if(root->right) temp+=root->right->data;

    if(temp>=root->data) root->data=temp;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }
    childrensumprop(root->left);
    childrensumprop(root->right);

    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;
    if(root->left || root->right) root->data = sum;
}






int main(){


    Node* root=new Node(40);
    root->left=new Node(10);
    root->right=new Node(20);
    root->left->left=new Node(2);
    root->left->right=new Node(5);
    root->right->left=new Node(30);
    root->right->right=new Node(40);

    // root->left->left->left=new Node(8);
    // root->left->left->right=new Node(9);
    

    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(11);
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    vector<vector<int>> res=levelorder(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    childrensumprop(root);

    vector<vector<int>> ans=levelorder(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}