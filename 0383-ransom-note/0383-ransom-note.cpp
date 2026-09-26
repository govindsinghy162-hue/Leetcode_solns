class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for(char c : magazine) {
            have[c]++;
        }

        for(char c : ransomNote) {
            need[c]++;
        }

        for(auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if(fhave < fneed) {
                return false;
            }
        }

        return true;
    }
};