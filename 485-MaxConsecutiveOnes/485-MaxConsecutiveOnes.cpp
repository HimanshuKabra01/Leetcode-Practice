// Last updated: 9/1/2025, 11:54:12 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int freq = 0;
        int maxFreq = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                freq++;
            } else {
                freq = 0;
            }

            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    }
};