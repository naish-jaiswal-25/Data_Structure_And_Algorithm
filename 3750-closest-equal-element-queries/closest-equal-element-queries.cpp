class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: store all indices of each value
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        // Step 2: process each query
        for (int q : queries) {
            int val = nums[q];
            auto &v = mp[val];

            // if only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // find position of q in vector
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int res = INT_MAX;

            // left neighbor (circular)
            int left = v[(pos - 1 + v.size()) % v.size()];
            int d1 = abs(q - left);
            res = min(res, min(d1, n - d1));

            // right neighbor (circular)
            int right = v[(pos + 1) % v.size()];
            int d2 = abs(q - right);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};