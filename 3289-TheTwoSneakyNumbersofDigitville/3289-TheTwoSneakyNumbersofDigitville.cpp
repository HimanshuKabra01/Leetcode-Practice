// Last updated: 10/31/2025, 10:02:07 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto &entry : mp) {
            if(entry.second == 2) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};