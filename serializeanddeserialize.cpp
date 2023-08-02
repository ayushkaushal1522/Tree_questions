string serialize(TreeNode* root) {
        if(!root) return "";
        string str="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* it = q.front();
            q.pop();
            if(it==NULL) str.append("#,");
            else str.append(to_string(it->val)+",");
            if(it!=NULL) q.push(it->left);
            if(it!=NULL) q.push(it->right);

        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left=NULL;
            }
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left =leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right=NULL;
            }
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right =rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }