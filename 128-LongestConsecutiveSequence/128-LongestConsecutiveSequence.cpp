// Last updated: 8/9/2026, 12:40:24 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }

        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        int ans = 0;
        int curr = 0;
        int num = 0;
        for(int x : st) {
            if(st.find(x-1) == st.end()) {
                num = x;
                num++;
                curr++;

                while(st.find(num) != st.end()) {
                    curr++;
                    num++;
                }

                ans = max(curr, ans);
                curr = 0;
            } else {
                curr = 0;
            }
        }

        return ans;
    }
};