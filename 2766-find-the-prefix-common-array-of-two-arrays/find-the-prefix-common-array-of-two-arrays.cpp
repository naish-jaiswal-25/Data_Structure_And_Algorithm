class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        unordered_set<int> seen;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (seen.count(A[i])) count++;
            seen.insert(A[i]);

            if (seen.count(B[i])) count++;
            seen.insert(B[i]);

            ans[i] = count;
        }

        return ans;
    }
};