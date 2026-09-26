class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        int ans = 0;
        bool odd = false;

        for(auto i : freq) {
            if(i.second % 2 == 0) {
                ans += i.second;
            }
            else {
                ans += i.second - 1;
                odd = true;
            }
        }

        if(odd) {
            ans++;
        }

        return ans;
    }
};