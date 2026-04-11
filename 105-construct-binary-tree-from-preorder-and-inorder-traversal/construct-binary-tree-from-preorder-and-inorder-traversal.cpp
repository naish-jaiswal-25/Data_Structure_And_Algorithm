class Solution {
public:
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l > r) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int i;
        for (i = l; i <= r; i++) {
            if (inorder[i] == rootVal) break;
        }

        root->left = build(preorder, inorder, l, i - 1);
        root->right = build(preorder, inorder, i + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};