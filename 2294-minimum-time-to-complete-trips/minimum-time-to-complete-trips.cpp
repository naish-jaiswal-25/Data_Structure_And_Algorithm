

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long trips = 0;
            for (int t : time) {
                trips += mid / t;

                if (trips >= totalTrips) break; // optimization
            }

            if (trips >= totalTrips) {
                high = mid; // try smaller time
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};