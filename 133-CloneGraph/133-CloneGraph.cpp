// Last updated: 9/26/2025, 7:58:04 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        
        for(int i = 0; i < n; i++) {
            if(s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            } else {
                return true;
                break;
            }
        }

        return false;
    }
};