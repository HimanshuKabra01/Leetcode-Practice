// Last updated: 8/9/2026, 12:39:11 PM
class Solution {
public:
    int rec(vector<int>& nums, int i, unordered_map<int, int> &mp) {
        if(mp.count(i)) return mp[i];
        if(i < 0) return 0;


        mp[i] =  max(nums[i] + rec(nums, i-2, mp), rec(nums, i-1, mp));
        return mp[i];
    }
    int rob(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = rec(nums, nums.size()-1, mp);

        return ans;
    }
};