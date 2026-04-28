class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        
        // Step 1: Flatten grid
        for (auto &row : grid) {
            for (auto &val : row) {
                arr.push_back(val);
            }
        }

        // Step 2: Check feasibility
        for (int i = 1; i < arr.size(); i++) {
            if ((arr[i] - arr[0]) % x != 0)
                return -1;
        }

        // Step 3: Sort
        sort(arr.begin(), arr.end());

        // Step 4: Find median
        int median = arr[arr.size() / 2];

        // Step 5: Count operations
        int ops = 0;
        for (int val : arr) {
            ops += abs(val - median) / x;
        }

        return ops;
    }
};