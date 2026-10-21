
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int maxEnding = 0, maxSum = nums[0];
        int minEnding = 0, minSum = nums[0];

        for (int x : nums) {
            maxEnding = max(x, maxEnding + x);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(x, minEnding + x);
            minSum = min(minSum, minEnding);

            total += x;
        }

        // All elements are negative
        if (maxSum < 0) {
            return maxSum;
        }

        // Normal subarray vs circular subarray
        return max(maxSum, total - minSum);
    }
};
