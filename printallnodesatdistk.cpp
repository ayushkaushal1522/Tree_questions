#include<bits/stdc++.h>
using namespace std;
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

void markparent(Node* root , unordered_map<Node* ,Node*> &mp){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->left){
            mp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            mp[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
vector<int> distk(Node* root , Node* target ,int k){
    unordered_map<Node* ,  Node*> mp;
    markparent(root,mp);
    unordered_map<Node* , bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] =true;
    int currlevel=0;
    while(!q.empty()){
        int s = q.size();
        if(currlevel==k) break;
        currlevel++;
        for(int i=0;i<s;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(mp[temp] && !visited[mp[temp]]){
                q.push(mp[temp]);
                visited[mp[temp]]=true;
            }
        }

    }
    vector<int> result;
    while(!q.empty()){
        auto it =q.front();
        q.pop();
        result.push_back(it->data);
    }
    return result;

}
int main(){




    return 0;
}