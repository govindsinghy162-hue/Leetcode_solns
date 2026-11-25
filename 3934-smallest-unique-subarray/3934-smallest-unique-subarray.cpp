class Solution {
public:
    using ull = unsigned long long;

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int len) {
            unordered_map<ull, int> mp;

            ull hash = 0;
            ull power = 1;
            const ull base = 47;

            for (int i = 0; i < len; i++) {
                hash = hash * base + nums[i];
                power *= base;
            }

            mp[hash]++;

            for (int i = len; i < n; i++) {
                hash = hash * base + nums[i]
                     - (ull)nums[i - len] * power;

                mp[hash]++;
            }

            for (auto &it : mp) {
                if (it.second == 1)
                    return true;
            }

            return false;
        };

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};