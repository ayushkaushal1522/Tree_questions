// skew tree can be considered as a one which is the flatten in nature.
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

Node* build(vector<int> &preorder , int ind ,int ub){
    if(ind==preorder.size() || preorder[ind]>ub) return NULL;
    Node* root = new Node(preorder[ind++]);
    root->left = build(preorder,ind,root->data);
    root->right = build(preorder ,ind ,ub);
    return root;

}

Node* bstpreorder(vector<int> &preorder){
    int i=0;
    return build(preorder ,i ,INT_MAX);
}

int main(){

    return 0;
}
