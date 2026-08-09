// Last updated: 8/9/2026, 12:29:38 PM
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
       int n = nums.size();
       int ans = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            unordered_set<int> st;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                st.insert(nums[j]);

                if(st.find(sum) != st.end()) {
                    ans++;
                }
            }
        }

        return ans;
    }
};