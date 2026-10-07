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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>fin;
        if(!root){
            return fin;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            vector<int> ans;
            while(lvl--){
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t -> val);
                if(t -> left != nullptr){
                    q.push(t->left);
                }
                if(t->right != nullptr){
                    q.push(t->right);
                }
            }
            fin.push_back(ans);
        }
        reverse(fin.begin(),fin.end());
        return fin;
    }
};