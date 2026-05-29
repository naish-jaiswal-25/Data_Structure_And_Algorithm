class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
            st.insert(reverseNum(num));
        }

        return st.size();
    }

    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
};