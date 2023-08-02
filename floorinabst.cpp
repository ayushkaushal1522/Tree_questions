#include<bits/stdc++.h>
using namespace std;

// time and space complexity of this particular algo is given by O(log(n)) for both

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


int findfloor(Node* root ,int temp){
    int floor=-1;
    while(root!=NULL){
        if(root->data==temp){
            floor = root->data;
            return floor;
        }
        if(temp>root->data){
            floor=root->data;
            root=root->right;
        }
        else{
            
            root = root->left;
        }
    }
    return floor;
}

int main(){



    return 0;
}