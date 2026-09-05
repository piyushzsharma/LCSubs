/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        queue<TreeNode*> q;
        q.push(root);
        string ans;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==nullptr) {
                ans+="#,";
                continue;
            }
            ans+=to_string(node->val)+",";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='#') return nullptr;
        stringstream ss(data);
        vector<string> val;
        string temp;
        //TreeNode* root=new TreeNode(data[0]);
        while(getline(ss,temp,',')){
            val.push_back(temp);
        }
        int i=1;
        TreeNode* root= new TreeNode(stoi(val[0]));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && i<val.size()){
            TreeNode* node=q.front();
            q.pop();
              if(val[i] != "#") {
            node->left = new TreeNode(stoi(val[i]));
            q.push(node->left);
        }
        i++;

    
        if(val[i] != "#") {
            node->right = new TreeNode(stoi(val[i]));
            q.push(node->right);
        }
        i++;
            
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));