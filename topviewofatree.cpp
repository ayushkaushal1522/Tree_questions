#include<bits/stdc++.h>
using namespace std;

// time complexity is given by O(n)log(n) where log(n) is because of the 
// multiset we are using. 

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



vector<int> topviewofatree(Node* root){
    map<int,int> mp;
    vector<int> ans;
    queue<pair<Node* ,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto node = q.front().first;
        int x = q.front().second;
        q.pop();
        if(mp.find(x)==mp.end()){
            mp[x]=node->data;
        }

        if(node->left) q.push({node->left,x-1});
        if(node->right)  q.push({node->right,x+1});


    }

    for(auto it :mp){
        ans.push_back(it.second);
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

    vector<int> res = topviewofatree(root);
    for(auto it : res){
        cout<<it<<" ";
    }
    cout<<endl;


    return 0;
}