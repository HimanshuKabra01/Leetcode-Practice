// Last updated: 9/22/2025, 10:32:58 PM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int elem = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int maxFreq = 0;
        for(auto &p : mp) {
            maxFreq = max(maxFreq, p.second);
        }

        for(int i = 0; i < n; i++){
            if(mp[nums[i]] == maxFreq) {
                elem++;
            }
        } 

        return elem;
    }
};