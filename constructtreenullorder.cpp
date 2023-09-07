#include<bits/stdc++.h>
using namespace std;
class Node{
            public:
                int data;
                Node* left;
                Node* right;
                Node(){
                    left=NULL;
                    right=NULL;
                }
    };
class Nullorder{
    
        
        public:
            Node* root;
        public:
            Nullorder(){
                root = createtree();
            }
        private:
            int strtoint(string str){
                int res = 0;
                for(char i : str){
                    res =res*10 + (i-'0');
                }
                return res;
            }
            Node* createtree(){
                string str;
                cin>>str;
                if(str=="NULL"){
                    return NULL;
                }
                
                Node* nn = new Node();
                nn->data = strtoint(str);
                nn->left = createtree();
                nn->right = createtree();
                return nn;
            }
        public:
            void preorder(){
                preorder(root);
            }
        
        private:
            void preorder(Node* root){
                if(root==NULL) return;
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }

    
};
int main(){

    
    Nullorder* lv = new Nullorder();
    lv->preorder();
    
   
   
    


    return 0;
}