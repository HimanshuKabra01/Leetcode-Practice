// Last updated: 8/9/2026, 12:29:01 PM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
       int n = nums.size();

       int sum = nums[n-1];
       int elem = 1;
       int ans = 0;

       for(int i = n - 2; i >= 0; i--) {
        int avg = sum / elem;
        if(nums[i] > avg) {
            ans++;
        }

        sum += nums[i];
        elem++;
       }

       return ans; 
    }
};