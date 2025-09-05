// Last updated: 9/5/2025, 2:30:40 PM
class Solution {
public:
    void getPermute(vector<int>& nums, vector<vector<int>>& ans, int idx){
        if(idx == nums.size()) {
            ans.push_back({nums});
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPermute(nums, ans, idx+1);
            //backtracking

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getPermute(nums, ans, 0);

        return ans;
    }
};