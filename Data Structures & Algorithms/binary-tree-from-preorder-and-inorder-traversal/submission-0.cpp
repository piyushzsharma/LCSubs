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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx){
        if(start>end) return NULL;

        int i=start;
        int rootval=0;
        for(;i<=end;i++){
            if(preorder[idx]==inorder[i]){
                rootval=inorder[i];
                break;
            }
        }
        idx++;

        TreeNode* root= new TreeNode(rootval);
        root->left=build(preorder,inorder,start,i-1,idx);
        root->right=build(preorder,inorder,i+1,end,idx);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        int n=preorder.size();
       // TreeNode* root=new TreeNode(preorder[idx]);
        return build(preorder,inorder,0,n-1,idx);

    }
};