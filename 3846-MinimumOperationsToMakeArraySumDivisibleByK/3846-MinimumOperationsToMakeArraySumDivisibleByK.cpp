// Last updated: 8/9/2026, 12:30:58 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return sum % k;
    }
};