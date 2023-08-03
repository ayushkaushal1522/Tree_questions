#include<bits/stdc++.h>
using namespace std;

// time and space complexity of this particular algo is given by O(1) .
// while space complexity is given by O(H) where H is the height of the binary tree. 

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

class BSTIterator {
    stack<Node *> st;
public:
    BSTIterator(Node *root) {
        pushAll(root);
    }

    
    bool hasNext() {
        return !st.empty();
    }

    int next() {
        Node *tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->data;
    }

private:
    void pushAll(Node *node) {
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    };
};