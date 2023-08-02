#include<bits/stdc++.h>
using namespace std;


// time complexity is given by O(log(n)) as we are just treversing the 
// length which  is equal to height of the tree at the worst case 


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

bool searchinabst(Node* root,int temp){
    while(root!=NULL && root->data!=temp){
        if(root->data>temp){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return root;
}


int main(){


    

    auto node = searchinabst(root,4);
    if(node) cout<<"present"<<endl;
    else cout<<"absent"<<endl;


    return 0;
}