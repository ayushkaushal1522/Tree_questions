#include<bits/stdc++.h>
using namespace std;
class LevelOrderTraversal {
	public:
		class Node {
			public:
				int data;
				Node* left;
				Node* right;
				Node(){
					left=NULL;
					right=NULL;
				}
		};
		private:
		    Node* root;
		public:
            LevelOrderTraversal() {
                root = createTree();
            }
        private:
            
            Node* createTree() {
                    int temp;
                    cin>>temp;

                    Node* node = new Node();
                    node->data = temp;
                    
                    string hasleft;
                    cin>>hasleft;
                    
                    if(hasleft=="true"){
                        node->left = createTree();
                    }
                    
                    string hasright;
                    cin>>hasright;
                   
                    if(hasright=="true"){
                        node->right = createTree();
                    }

                    return node;
                }
        public:
                void inorder(){
                        inorder(root);
                }
		private:
				void inorder(Node* root){
					if(root==NULL) return;
                    inorder(root->left);
                    cout<<root->data<<endl;
                    inorder(root->right);
				}
};


int main() {
	LevelOrderTraversal* lv = new LevelOrderTraversal();
	lv->inorder();
}