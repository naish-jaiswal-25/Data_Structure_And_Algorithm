class Solution {
public:
    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();

        vector<pair<long long,int>> pos;

        // Step 1: map to perimeter
        for (int i = 0; i < n; i++) {
            long long x = points[i][0], y = points[i][1];
            long long val;

            if (y == 0) val = x;
            else if (x == side) val = side + y;
            else if (y == side) val = 3LL * side - x;
            else val = 4LL * side - y;

            pos.push_back({val, i});
        }

        sort(pos.begin(), pos.end());

        // Step 2: extend
        vector<pair<long long,int>> ext = pos;
        for (int i = 0; i < n; i++) {
            ext.push_back({pos[i].first + 4LL * side, pos[i].second});
        }

        // Extract only perimeter values for binary search
        vector<long long> vals;
        for (auto &p : ext) vals.push_back(p.first);

        // Step 3: check
        auto can = [&](long long d) {
            for (int i = 0; i < n; i++) {
                int cnt = 1;
                long long last = ext[i].first;
                int lastIdx = ext[i].second;

                int cur = i;

                while (true) {
                    long long target = last + d;

                    // 🔥 jump using binary search
                    int nxt = lower_bound(vals.begin() + cur + 1,
                                          vals.begin() + i + n,
                                          target) - vals.begin();

                    if (nxt >= i + n) break;

                    cnt++;
                    last = ext[nxt].first;
                    lastIdx = ext[nxt].second;
                    cur = nxt;

                    if (cnt == k) {
                        // circular check
                        if (manhattan(points[ext[i].second],
                                      points[lastIdx]) >= d)
                            return true;
                        break;
                    }
                }
            }
            return false;
        };

        long long low = 0, high = 2LL * side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};