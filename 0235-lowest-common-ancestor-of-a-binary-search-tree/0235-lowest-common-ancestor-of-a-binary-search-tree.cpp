/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* fun (TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* ans = nullptr;
        if(root == nullptr) return ans;
        if(p == root || q == root){
            ans = root;
            return ans;
        }
        if(p->val > root->val && q->val > root->val ){
            return fun (root -> right,p,q);
        }
        else if(p->val < root->val && q->val < root->val){
            return fun (root -> left,p,q);
        }
        else{
            ans = root;
            return ans;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            return fun(root,p,q);
        }
        else{
            return fun (root,q,p);
        }
    }
    
};