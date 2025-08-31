// Last updated: 8/31/2025, 10:34:16 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n*(n+1)/2;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return total-sum;
    }
};