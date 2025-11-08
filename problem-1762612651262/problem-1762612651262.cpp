// Last updated: 11/8/2025, 8:07:31 PM
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxElement = nums[0];
        int ans = 0;

        if(n == 1) {
            return 0;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxElement) {
                maxElement = nums[i];
            }
        }

        for(int i = 0; i < n; i++) {
            if(maxElement != nums[i]) {
                ans += maxElement - nums[i];
            }
        }

        return ans;
    }
};