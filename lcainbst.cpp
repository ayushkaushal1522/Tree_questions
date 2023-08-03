// whenever it is the case of bst then we should think about the algo which runs in O(log(n)) time complexity. 
// you are traversing the tree from the beginning that is form the root and the first point wheere the 
// path splits will be the point of lca as it is the case of binary searhch tree.#include<bits/stdc++.h>
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

Node* lca(Node* root , Node* p , Node* q){
    if(root==NULL) return NULL;
    int temp = root->data;
    if(temp<p->data && temp<q->data){
        return lca(root->right,p,q);
    }
    if(temp>p->data && temp>q->data){
        return lca(root->left,p,q);
    }
    return root;
}

int main(){



    return 0;
}