#include<bits/stdc++.h>
using namespace std;

//Almost same code as that of the print all nodes at a distance k.
//The simple approach is 
//1)first mark all the parents in the some map like ,
//2)because from one node we can travel in one of the three direction 
// which are left , right and the parent as well.
// 3)now it has been made a question like graph.


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

int main(){


    return 0;
}