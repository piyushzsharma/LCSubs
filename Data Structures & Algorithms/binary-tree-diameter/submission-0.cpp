/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result=0;

    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        result=max(result,l+r);



        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return result;
    }
};