#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int p : piles) {
            hours += (p + k - 1) / k; // ceil(p/k)
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {
                high = mid; // try smaller speed
            } else {
                low = mid + 1; // increase speed
            }
        }

        return low;
    }
};