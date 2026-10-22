class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                break;
            }
        }

        if (sorted) return 0;

        // Case 1: Rotation of the sorted array
        int k = nums[0];
        bool normal = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) {
                normal = false;
                break;
            }
        }

        int ans = INT_MAX;

        if (normal) {
            ans = min(n - k, k + 2);
        }

        // Case 2: Rotation of the reversed sorted array
        int j = (n - 1 - nums[0] + n) % n;
        bool reversed = true;

        for (int i = 0; i < n; i++) {
            int expected = (n - 1 - (j + i) % n);

            if (nums[i] != expected) {
                reversed = false;
                break;
            }
        }

        if (reversed) {
            ans = min(ans, min(n - j + 1, j + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};