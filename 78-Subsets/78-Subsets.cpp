// Last updated: 9/2/2025, 6:33:39 PM
class Solution {
public:
    void getAll(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets){
        if(i == nums.size()) {
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getAll(nums, ans, i+1, allSubsets);

        ans.pop_back();
        getAll(nums, ans, i+1, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;

        getAll(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};