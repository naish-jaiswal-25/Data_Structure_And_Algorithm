class Solution {
public:
    int countWalls(vector<int>& walls, int L, int R) {
        if(L > R) return 0;
        return upper_bound(walls.begin(), walls.end(), R) -
               lower_bound(walls.begin(), walls.end(), L);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        vector<pair<int,int>> r(n);
        for(int i = 0; i < n; i++) {
            r[i] = {robots[i], distance[i]};
        }
        
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());
        
        vector<int> leftL(n), rightR(n);
        vector<int> leftCount(n), rightCount(n);
        
        for(int i = 0; i < n; i++) {
            int pos = r[i].first;
            int d = r[i].second;
            
            int leftBlock = (i > 0 ? r[i-1].first : INT_MIN);
            int rightBlock = (i < n-1 ? r[i+1].first : INT_MAX);
            
            int L = max(pos - d, leftBlock + 1);
            int R = pos;
            leftL[i] = L;
            leftCount[i] = countWalls(walls, L, R);
            
            L = pos;
            R = min(pos + d, rightBlock - 1);
            rightR[i] = R;
            rightCount[i] = countWalls(walls, L, R);
        }
        
        vector<int> dpL(n), dpR(n);
        
        dpL[0] = leftCount[0];
        dpR[0] = rightCount[0];
        
        for(int i = 1; i < n; i++) {
            // overlap between right[i-1] and left[i]
            int overlap = countWalls(walls,
                max(r[i-1].first, leftL[i]),
                min(rightR[i-1], r[i].first)
            );
            
            dpL[i] = max(
                dpL[i-1],
                dpR[i-1] - overlap
            ) + leftCount[i];
            
            dpR[i] = max(
                dpR[i-1],
                dpL[i-1]
            ) + rightCount[i];
        }
        
        return max(dpL[n-1], dpR[n-1]);
    }
};