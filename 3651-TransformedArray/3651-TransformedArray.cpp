// Last updated: 8/9/2026, 12:31:07 PM
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                int idx = i + nums[i];

                ans[i] = nums[(idx % n)];
            } else if(nums[i] < 0) {
                int idx = i - abs(nums[i]);

                ans[i] = nums[( (idx % n) + n ) % n];
            } else {
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};