#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;  // not enough elements

        sort(nums.begin(), nums.end());  // Step 1: sort

        for (int i = 0; i < n - 2; i++) {
            // Step 4: skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Move left and right and skip duplicates
                    int leftVal = nums[left];
                    int rightVal = nums[right];

                    while (left < right && nums[left] == leftVal) left++;
                    while (left < right && nums[right] == rightVal) right--;
                }
                else if (sum < 0) {
                    // Need bigger sum → move left
                    left++;
                }
                else {
                    // sum > 0 → need smaller sum → move right
                    right--;
                }
            }
        }

        return result;
    }
};
