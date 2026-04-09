class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        ans.push_back(root->val);     // root
        preorder(root->left, ans);    // left
        preorder(root->right, ans);   // right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};