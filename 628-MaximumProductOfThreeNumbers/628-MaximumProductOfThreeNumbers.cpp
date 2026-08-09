// Last updated: 8/9/2026, 12:36:36 PM
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int n = nums.size();

       sort(nums.begin(), nums.end());

       int ans = 0;

       int st = nums[0]*nums[1];
       int end = nums[n-1]*nums[n-2];

       ans = max(end*nums[n-3], st*nums[n-1]);

       return ans;
    }
};