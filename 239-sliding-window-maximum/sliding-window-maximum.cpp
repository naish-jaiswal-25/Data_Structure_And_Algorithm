class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove out of window elements
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Push current index
            dq.push_back(i);

            // Store result
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};