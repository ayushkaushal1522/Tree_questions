#include<bits/stdc++.h>
using namespace std;

// time complexity is given by O(logn^2).
// space complexity is given by O(logn).
https://github.com/ayushkaushal1522/Tree_questions.git
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

int findheightleft(Node* root){
    int h=0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}
int findheightright(Node* root){
    int h=0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}


int countnodes(Node* root){
    if(root==NULL) return 0;
    int l = findheightleft(root);
    int r = findheightright(root);

    if(l==r) return (1<<l)-1;

    return 1+countnodes(root->left)+countnodes(root->right);


}



int main(){

    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // root->left->left->left=new Node(8);
    // root->left->left->right=new Node(9);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(11);
    // root->right->left->left = new Node(12);
    // root->right->left->right = new Node(13);
    // root->right->right->left = new Node(14);
    // root->right->right->right = new Node(15);

    cout<<countnodes(root)<<endl;





    return 0;
}