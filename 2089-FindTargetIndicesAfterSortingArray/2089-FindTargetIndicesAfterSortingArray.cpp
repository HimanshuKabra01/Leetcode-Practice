// Last updated: 7/17/2025, 5:17:20 PM
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