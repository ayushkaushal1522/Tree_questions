//we can definately make a tree using the preorder and post order traversal but for making the unique 
//binary tree it ismust that we have inorder traversal array with us.
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
Node* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;
        Node* root = new Node(postorder[pe]);
        int ri = hm[postorder[pe]];
        Node* leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        Node* rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root->left = leftchild;
        root->right = rightchild;
        return root;
    }
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if (inorder.size() != postorder.size())
            return NULL;
        map<int,int> hm;
        for (int i=0;i<inorder.size();++i)
            hm[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,hm);
    }
    

 
int main(){












    return 0;
}