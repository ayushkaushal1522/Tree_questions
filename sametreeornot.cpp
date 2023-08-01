#include<bits/stdc++.h>
using namespace std;

//Time complexity for the  particular algorithm is O(n),
//space complexity for the particular algorithm is also given by O(n) only.


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

bool sametree(Node* root1 , Node* root2){
    if(root1==NULL || root2==NULL) return (root1==root2);
    if(root1->data!=root2->data) return false;
    if(sametree(root1->left , root2->left)==false) return false;
    if(sametree(root1->right , root2->right)==false) return false;
    return true;
    

}


int main(){


    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);



    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    // root2->right->left = new Node(6);

    cout<<sametree(root1,root2)<<endl;

    return 0;
}


