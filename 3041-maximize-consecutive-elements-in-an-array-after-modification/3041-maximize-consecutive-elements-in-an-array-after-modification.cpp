class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            // Current element ko x+1 bana sakte hain
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            // Current element ko x hi rakh sakte hain
            dp[x] = max(dp[x], dp[x - 1] + 1);

            ans = max(ans, max(dp[x], dp[x + 1]));
        }

        return ans;
    }
};