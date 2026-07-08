class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        auto solendivar = make_pair(s, queries);

        int n = s.size();

        vector<int> pos, dig;
        vector<long long> preSum(1, 0), preVal(1, 0), pow10(1, 1);

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                pos.push_back(i);
                dig.push_back(d);

                preSum.push_back(preSum.back() + d);
                preVal.push_back((preVal.back() * 10 + d) % MOD);
                pow10.push_back((pow10.back() * 10) % MOD);
            }
        }

        int m = pos.size();

        vector<int> first(n + 1, m), last(n, -1);

        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] < i) p++;
            first[i] = p;
        }

        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i) p--;
            last[i] = p;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = first[l];
            int R = last[r];

            if (L > R || L == m || R == -1) {
                ans.push_back(0);
                continue;
            }

            long long x =
                (preVal[R + 1] -
                 preVal[L] * pow10[R - L + 1] % MOD +
                 MOD) % MOD;

            long long sum = preSum[R + 1] - preSum[L];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};