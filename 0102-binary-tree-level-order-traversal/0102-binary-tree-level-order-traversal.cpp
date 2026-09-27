class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        if (!root) return ans;
        q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            vector<int>tmp;
            while(lvl--){
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left != nullptr ){
                    q.push(t->left);
                }
                if(t->right != nullptr ){
                    q.push(t->right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};