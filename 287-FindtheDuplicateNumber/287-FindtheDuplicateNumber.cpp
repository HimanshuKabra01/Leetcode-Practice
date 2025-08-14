// Last updated: 8/14/2025, 7:20:41 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        int ans;

        for(int i = 0; i < n; i++) {
            if(s.find(nums[i]) != s.end()) {
                ans = nums[i];
            }

            s.insert(nums[i]);
        }

        return ans;
    }
};