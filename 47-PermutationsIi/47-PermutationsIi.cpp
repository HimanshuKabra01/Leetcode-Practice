// Last updated: 8/9/2026, 12:42:21 PM
class Solution {
public:
    set<vector<int>> s;
    void getPermute(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            if(s.find(nums) == s.end()) {
                ans.push_back({nums});
                s.insert(nums);
            }
            return;
        }

        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPermute(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        getPermute(nums, 0, ans);

        return ans;
    }
};