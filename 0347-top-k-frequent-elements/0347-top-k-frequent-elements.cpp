class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : mp) {
            int element = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(element);
        }

        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            
            for (int x : bucket[i]) {
                ans.push_back(x);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};