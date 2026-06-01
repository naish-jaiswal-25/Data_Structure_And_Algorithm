class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size() - 1;

        if (nums[n] != n) return false;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return false;
        }

        return true;
    }
};