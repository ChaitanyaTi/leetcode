/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void fun(TreeNode* root, int targetSum, int sum, bool &res) {
        if(root == nullptr){
            return;
        }
        sum += root->val;
        if(root -> left == nullptr && root -> right == nullptr){
            if(sum == targetSum){
                res = true;
            }
            return;
        }
        fun(root -> left, targetSum,sum,res);
        fun(root -> right, targetSum,sum,res);
    }    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        fun(root, targetSum, 0, res);
        return res;
    }
};