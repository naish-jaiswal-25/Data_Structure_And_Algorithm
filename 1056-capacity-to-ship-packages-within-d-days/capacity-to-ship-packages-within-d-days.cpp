#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap) {
        int d = 1, curr = 0;

        for (int w : weights) {
            if (curr + w > cap) {
                d++;
                curr = 0;
            }
            curr += w;
        }

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                high = mid;  // try smaller
            } else {
                low = mid + 1; // increase capacity
            }
        }

        return low;
    }
};