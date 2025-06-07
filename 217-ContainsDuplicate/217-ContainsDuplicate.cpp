// Last updated: 6/7/2025, 5:39:24 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n == 2) {
            if(nums[0] == nums[1]) {
                return true;
            }
        }

        for(int i = 1; i < n-1; i++) {
            if(nums[i] == nums[i+1] || nums[i-1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
};