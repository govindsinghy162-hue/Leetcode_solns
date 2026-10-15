
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.size()) {
            // Characters match or '?' matches any character
            if (j < p.size() &&
                (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // Remember the position of '*'
            else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            }
            // Try matching one more character with '*'
            else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            }
            // No match possible
            else {
                return false;
            }
        }

        // Remaining pattern characters must all be '*'
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};
