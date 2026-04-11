class Solution {
public:
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int l, int r) {
        if (l > r) return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (l == r) return root;

        int leftChild = preorder[preIndex];

        int i;
        for (i = l; i <= r; i++) {
            if (postorder[i] == leftChild) break;
        }

        root->left = build(preorder, postorder, l, i);
        root->right = build(preorder, postorder, i + 1, r - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, postorder, 0, postorder.size() - 1);
    }
};