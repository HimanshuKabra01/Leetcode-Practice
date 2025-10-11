// Last updated: 10/11/2025, 9:24:55 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2;

        for(int i = 0; i < n-1; i++) {
            int a = nums[i];
            int b = nums[i+1];
            int len = 2;
            int k = i + 2;

            while(k < n) {
                if(nums[k] == a+b) {
                    len++;
                    a = b;
                    b = nums[k];
                } else {
                    break;
                }

                k++;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
        
    }
};