// Last updated: 8/9/2026, 12:38:42 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans;
       unordered_map<int, int> mp;

       sort(nums.begin(), nums.end());

       for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
       }

       for(auto &entry : mp) {
            if(entry.second > n/3) {
                ans.push_back(entry.first);
            }
       }

       return ans;
    }
};