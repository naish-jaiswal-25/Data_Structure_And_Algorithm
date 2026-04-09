class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (root == NULL) return;

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};