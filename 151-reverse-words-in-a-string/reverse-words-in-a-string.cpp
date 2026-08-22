class Solution {
public:
    string reverseWords(string s) {

        // Remove extra spaces
        int i = 0, j = 0;

        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ')
                i++;

            if (i < s.size() && j > 0)
                s[j++] = ' ';

            while (i < s.size() && s[i] != ' ')
                s[j++] = s[i++];
        }

        s.resize(j);

        // Reverse complete string
        reverse(s.begin(), s.end());

        // Reverse every word
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};