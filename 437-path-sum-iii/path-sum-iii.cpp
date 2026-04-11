class Solution {
public:
    unordered_map<long long, int> mp;

    int dfs(TreeNode* root, long long currSum, int target) {
        if (!root) return 0;

        currSum += root->val;

        int count = mp[currSum - target];

        mp[currSum]++;

        count += dfs(root->left, currSum, target);
        count += dfs(root->right, currSum, target);

        mp[currSum]--; // backtrack

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return dfs(root, 0, targetSum);
    }
};