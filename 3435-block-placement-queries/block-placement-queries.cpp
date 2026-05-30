class FenwickTree {
public:
    vector<int> bit;

    FenwickTree(int n) {
        bit.resize(n + 2, 0);
    }

    void update(int i, int val) {
        while (i < bit.size()) {
            bit[i] = max(bit[i], val);
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, bit[i]);
            i -= i & -i;
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = min(50000, (int)queries.size() * 3);
        vector<bool> ans;

        set<int> obstacles = {0, n};
        FenwickTree ft(n + 2);

        // add all obstacles first
        for (auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        // initialize gaps
        for (auto it = obstacles.begin(); next(it) != obstacles.end(); ++it) {
            int a = *it;
            int b = *next(it);
            ft.update(b + 1, b - a);
        }

        // process backward
        for (int i = queries.size() - 1; i >= 0; --i) {
            auto& q = queries[i];

            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.find(x);

                int left = *prev(it);
                int right = *next(it);

                obstacles.erase(it);
                ft.update(right + 1, right - left);

            } else {
                int x = q[1];
                int sz = q[2];

                int best = ft.query(x + 1);

                auto it = obstacles.upper_bound(x);
                int left = *prev(it);

                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};