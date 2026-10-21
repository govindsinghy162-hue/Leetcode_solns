class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int end = start + k;
                int descents = 0;

                for (int j = start; j < end - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        descents++;
                    }
                }

                if (descents > 1 ||
                    (descents == 1 && nums[end - 1] > nums[start])) {
                    valid = false;
                    break;
                }

                int mn = *min_element(nums.begin() + start,
                                      nums.begin() + end);
                int mx = *max_element(nums.begin() + start,
                                      nums.begin() + end);

                if (mn < prevMax) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};