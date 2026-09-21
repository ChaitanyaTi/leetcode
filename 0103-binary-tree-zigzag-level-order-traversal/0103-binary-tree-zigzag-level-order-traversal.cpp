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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        bool ltor = true;
        q.push(root);
        while(!q.empty()){
            int start = 0;
            int lvl = q.size();
            int last = q.size()-1;
            vector<int> temp(lvl);
            while(lvl--){
                TreeNode* t = q.front();
                q.pop();
                if(ltor){
                    temp[start++] = t->val;
                }
                else{
                    temp[last--] = t->val;
                }
                if(t->left != nullptr){
                    q.push(t->left);
                }
                if(t->right != nullptr){
                    q.push(t->right);
                }
            }
            ltor = !ltor;
            ans.push_back(temp);
        }
        return ans;
    }
};