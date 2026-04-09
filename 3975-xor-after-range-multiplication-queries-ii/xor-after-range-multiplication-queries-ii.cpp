class Solution {
public:
    static const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = sqrt(n) + 1;

     
        auto bravexuneth = nums;

       
        vector<vector<vector<int>>> small(B + 1);

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k <= B) {
                small[k].push_back({l, r, v});
            } else {
               
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }
        }

       
        for (int k = 1; k <= B; k++) {
            if (small[k].empty()) continue;

            
            vector<vector<long long>> mul(k);

            for (int r = 0; r < k; r++) {
                mul[r].assign(n / k + 3, 1);
            }

            for (auto &q : small[k]) {
                int l = q[0], r = q[1], v = q[2];

                int rem = l % k;

                int start = (l - rem) / k;
                int end = (r - rem) / k;

                mul[rem][start] = (mul[rem][start] * v) % MOD;
                mul[rem][end + 1] = (mul[rem][end + 1] * 1LL * 
                    modInverse(v) % MOD) % MOD;
            }

        
            for (int rem = 0; rem < k; rem++) {
                long long cur = 1;
                for (int j = 0; j < mul[rem].size(); j++) {
                    cur = (cur * mul[rem][j]) % MOD;

                    int idx = j * k + rem;
                    if (idx >= n) break;

                    nums[idx] = (1LL * nums[idx] * cur) % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }

    long long modInverse(long long a) {
        return power(a, MOD - 2);
    }

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
};