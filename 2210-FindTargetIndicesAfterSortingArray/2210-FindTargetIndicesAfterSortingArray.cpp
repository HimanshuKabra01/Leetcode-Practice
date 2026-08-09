// Last updated: 8/9/2026, 12:32:25 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                ans.push_back(i);
            }
        }


        return ans;
    }
};