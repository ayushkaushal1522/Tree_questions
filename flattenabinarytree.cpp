#include<bits/stdc++.h>
using namespace std;


//brute force as it is taking extra space for the stack of integer we are using.

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

void flatten(Node* root) {
		if(root == NULL) return; 
		stack<Node*> st; 
		st.push(root); 
		while(!st.empty()) {
			Node* cur = st.top(); 
			st.pop(); 

			if(cur->right != NULL) {
				st.push(cur->right); 
			}
			if(cur->left != NULL) {
				st.push(cur->left); 
			}
			if(!st.empty()) {
				cur->right = st.top(); 
			}
			cur->left = NULL;
		}
    
}

//more optimize one 
//space complexity for this particular alogorithm is O(1) mere dost.
void flattenthetree(Node* root){
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left!=NULL){
            Node* node = curr->left;
            while(node->right!=NULL){
                node=node->right;
            }
            node->right=curr->right;
            curr->right=node;
            curr->left=NULL;
        }
        curr=curr->right;
    }
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
    
    cout<<root->right->right->data<<endl;

    flattenthetree(root);

    cout<<root->right->right->data<<endl;



    return 0;
}