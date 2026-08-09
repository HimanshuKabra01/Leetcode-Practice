// Last updated: 8/9/2026, 12:31:05 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;

        for(int x : nums) {
            totalSum += x;
        }

        if(totalSum % 2 != 0) {
            return 0;
        } else {
            return nums.size() - 1;
        }
    }
};