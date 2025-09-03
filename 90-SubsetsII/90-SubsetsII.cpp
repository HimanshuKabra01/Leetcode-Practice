// Last updated: 9/3/2025, 6:48:19 PM
class Solution {
public:
    void getAll(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& allSubsets){
        int n = nums.size();
        if(i == n) {
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        getAll(nums, i+1, ans, allSubsets);
        ans.pop_back();

        int idx = i + 1;
        while(idx < n && nums[idx] == nums[idx-1]) idx++;

        getAll(nums, idx, ans, allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> allSubsets;

        getAll(nums, 0, ans, allSubsets);

        return allSubsets;
    }
};