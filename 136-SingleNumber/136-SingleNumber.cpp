// Last updated: 6/7/2025, 5:39:32 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans = 0;

       for(int val : nums) {
        ans ^= val;
       }

       return ans; 
    }
};