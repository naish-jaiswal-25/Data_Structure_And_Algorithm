class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int ans = INT_MAX; // initialize answer with maximum value
        
        // traverse the array
        for(int i = 0; i < nums.size(); i++) {
            
            // check if current element is target
            if(nums[i] == target) {
                
                // calculate distance
                int distance = abs(i - start);
                
                // update minimum distance
                ans = min(ans, distance);
            }
        }
        
        return ans; // return the minimum distance
    }
};