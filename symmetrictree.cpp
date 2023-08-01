#include<bits/stdc++.h>
using namespace std;

//Time complexity for the  particular algorithm is O(n),
//space complexity for the particular algorithm is also given by O(n) only.
// as it is the simple traversal algorithms only yaar.

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

bool symmetrictree(Node* root1 , Node* root2){
    if(root1==NULL || root2==NULL) return (root1==root2);
    if(root1->data!=root2->data) return false;
    if(symmetrictree(root1->left , root2->right)==false) return false;
    if(symmetrictree(root1->right , root2->left)==false) return false;
    return true;
    

}


int main(){


    Node* root=new Node(1);
    root->left=new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right= new Node(8);


    

    cout<<symmetrictree(root->left,root->right)<<endl;

    return 0;
}


