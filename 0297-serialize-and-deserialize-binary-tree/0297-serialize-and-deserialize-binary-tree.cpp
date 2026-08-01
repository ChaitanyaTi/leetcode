class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string> q;
        
        while (getline(ss, item, ',')) {
            q.push(item);
        }
        
        return helper(q);
    }

private:
    TreeNode* helper(queue<string>& q) {
        if (q.empty()) return nullptr;
        
        string val = q.front();
        q.pop();
        
        if (val == "#") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = helper(q);
        node->right = helper(q);
        
        return node;
    }
};