class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        vector<int> slots;
        for (auto &f : factories) {
            int pos = f[0], cap = f[1];
            for (int i = 0; i < cap; i++) {
                slots.push_back(pos);
            }
        }

        int n = robots.size();
        int m = slots.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

        // base case
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                // option 1: skip this slot
                dp[i][j] = dp[i][j + 1];

                // option 2: assign robot to this slot
                long long cost = abs(robots[i] - slots[j]) + dp[i + 1][j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }

        return dp[0][0];
    }
};