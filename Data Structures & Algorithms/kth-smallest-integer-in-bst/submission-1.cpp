class Solution {
public:
    int KthSmallest(TreeNode* root, int& k) {
        if(!root) return -1;

        int left = KthSmallest(root->left, k);

        if(k == 0)
            return left;

        k--;

        if(k == 0)
            return root->val;

        return KthSmallest(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return KthSmallest(root, k);
    }
};