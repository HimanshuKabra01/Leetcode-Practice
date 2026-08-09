// Last updated: 8/9/2026, 12:29:16 PM
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i = n - 1; i > 0; i--) {
            if(nums[i] - nums[i-1] > 0) {
                ans++;
            } else {
                break;
            }
        }

        return n - ans -1;
    }
};