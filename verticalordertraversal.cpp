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



vector<vector<int>> verticaltraversal(Node* root){
    map<int,map<int,multiset<int>>> mp;
    queue<pair<Node* ,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int x = it.second.first;
        int y = it.second.second;
        mp[x][y].insert(node->data);
        if(node->left){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            q.push({node->right,{x+1,y+1}});
        }

    }
    vector<vector<int>> ans;
    for(auto it  :mp){
        vector<int> temp;
        for(auto jt : it.second){
            temp.insert(temp.end() , jt.second.begin() , jt.second.end());

        }
        ans.push_back(temp);
    }
    return ans;
}


int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(10);
    root->right->left=new Node(9);
    root->right->right=new Node(10);

    // root->left->left->left=new Node(8);
    root->left->left->right=new Node(5);
    root->left->left->right->right=new Node(6);

    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(11);
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    vector<vector<int>> res=verticaltraversal(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}