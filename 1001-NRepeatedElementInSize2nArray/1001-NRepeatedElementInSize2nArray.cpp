// Last updated: 8/9/2026, 12:34:50 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) {
                return nums[i];
            } else {
                s.insert(nums[i]);
            }
        }

        return -1;
    }
};