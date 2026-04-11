class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : mp) {
            auto &v = it.second;

            if (v.size() < 3) continue;

            // check consecutive triplets
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};