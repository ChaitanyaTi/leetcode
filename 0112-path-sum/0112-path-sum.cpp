class Solution {
public:
    void has(TreeNode* root, int currentSum, int targetSum, bool &res) {
        if (!root || res) return;

        currentSum += root->val;

        // Check if the current node is a leaf
        if (!root->left && !root->right) {
            if (currentSum == targetSum) {
                res = true;
            }
            return;
        }

        has(root->left, currentSum, targetSum, res);
        has(root->right, currentSum, targetSum, res);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        has(root, 0, targetSum, res);
        return res;
    }
};