// Last updated: 6/24/2025, 12:07:11 AM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for(int val : nums) {
            currSum += val;

            maxSum = max(currSum, maxSum);

            if(currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;  
    }
};