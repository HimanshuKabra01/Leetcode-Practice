// Last updated: 8/9/2026, 12:34:44 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int sq = nums[i]*nums[i];

            ans.push_back(sq);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};