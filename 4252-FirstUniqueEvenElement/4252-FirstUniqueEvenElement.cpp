// Last updated: 8/9/2026, 12:28:29 PM
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                if(mp[nums[i]] == 1) {
                    ans = nums[i];
                    break;
                }
            } else {
                continue;
            }
        }

        return ans;
    }
};