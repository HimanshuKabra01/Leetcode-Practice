// Last updated: 8/9/2026, 12:29:51 PM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        sort(nums.begin(), nums.end());

        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int s = nums[0];
        int end = nums[n-1];

        for(int i = s+1; i < end; i++) {
            if(st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};