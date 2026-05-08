class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor (SPF)
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (long long i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // prime -> indices divisible by that prime
        unordered_map<int, vector<int>> bucket;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            unordered_set<int> used;

            while (x > 1) {
                int p = spf[x];

                if (!used.count(p)) {
                    bucket[p].push_back(i);
                    used.insert(p);
                }

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return steps;

                // move left
                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                // move right
                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                int val = nums[i];

                // teleport only if val is prime
                if (val > 1 && spf[val] == val) {

                    for (int idx : bucket[val]) {
                        if (!vis[idx]) {
                            vis[idx] = 1;
                            q.push(idx);
                        }
                    }

                    // important optimization
                    bucket[val].clear();
                }
            }

            steps++;
        }

        return -1;
    }
};