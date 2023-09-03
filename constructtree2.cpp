#include<bits/stdc++.h>
using namespace std;
class LevelOrder{
    public:
        class Node{
            public:
                int data;
                Node* left;
                Node* right;
            
        };
    private:
        Node* root;
    public:
        LevelOrder(){
            createtree();
        }
    private:
        void createtree(){
            int temp;
            cin>>temp;
            Node* node = new Node();
            node->data = temp;
            root=node;
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* rem =  q.front();
                q.pop();
                int c1,c2;
                cin>>c1>>c2;
                if(c1!=-1){
                    Node* a = new Node();
                    a->data = c1;
                    rem->left = a;
                    q.push(a);
                }
                if(c2!=-1){
                    Node* b = new Node();
                    b->data = c2;
                    rem->right = b;
                    q.push(b);
                }

            }
        }
    public:
        void inorder(){
            inorder(root);
        }
    private:
        void inorder(Node* root){
            if(root==NULL) return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);

        }


};
int main(){

    LevelOrder* lv = new LevelOrder();
    lv->inorder();



    return 0;
}