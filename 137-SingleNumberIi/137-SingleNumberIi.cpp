// Last updated: 6/7/2025, 5:39:31 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int freq = 1;
        int ans = nums[0];

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1]) {
                freq++;
            } else if(nums[i] != nums[i+1] && freq == 1) {
                ans = nums[i];
                break;
            } else if(nums[i] != nums[i+1]) {
                freq = 1;
                ans = nums[i+1];
            } 
        }
        return ans;
    }
};