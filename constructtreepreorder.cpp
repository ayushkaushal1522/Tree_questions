#include<bits/stdc++.h>
using namespace std;
class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(){
			left = NULL;
			right = NULL;
		}
};
void func(TreeNode* root){
					if(root==NULL) return;
                    if(root->left==NULL){
						cout<<"END => ";
					}
					else{
						cout<<root->left->val<<" => ";
					}
					cout<<root->val<<" <= ";
					if(root->right==NULL){
						cout<<"END "<<endl;
					}
					else{
						cout<<root->right->val<<endl;
					}
					func(root->left);
                    func(root->right);
	}
 TreeNode* make(vector<int> &preorder , int& ind ,int ub){
    if(ind==preorder.size() || preorder[ind]>ub) return NULL;
    TreeNode* root = new TreeNode();
	root->val = preorder[ind];
	ind++;
    root->left = make(preorder,ind,root->val);
    root->right = make(preorder ,ind ,ub);
    return root;

}
TreeNode* funco(vector<int>& preorder) {
        int i=0;
        return make(preorder ,i ,INT_MAX);
}
void addduplicatenodes(TreeNode* root){
	if(root==NULL) return;
	TreeNode* temp = new TreeNode();
	temp->val = root->val;
	TreeNode* tempo = root->left;
	root->left = temp;
	temp->left = tempo;
	addduplicatenodes(root->left->left);
	addduplicatenodes(root->right);
}
void inorder(TreeNode* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);

}
int main() {
	int n;
	cin>>n;
	vector<int> preorder(n);
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	TreeNode* res = funco(preorder);
	addduplicatenodes(res);
	func(res);

	return 0;
}