// Last updated: 8/9/2026, 12:28:48 PM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        unordered_map<int, int> freq;

        for(auto &entry : m) {
            freq[entry.second]++;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(freq[m[nums[i]]] == 1) {
                return nums[i];
            } 
        }

        return -1;
    }
};