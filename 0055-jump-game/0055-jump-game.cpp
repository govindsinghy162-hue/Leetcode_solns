
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If current index is not reachable
            if (i > maxReach) {
                return false;
            }

            // Update maximum reachable index
            maxReach = max(maxReach, i + nums[i]);

            // If last index is reachable
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};
