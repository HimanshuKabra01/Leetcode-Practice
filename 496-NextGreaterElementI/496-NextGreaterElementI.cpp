// Last updated: 8/9/2026, 12:37:17 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n);
        vector<int> next(m);
        stack<int> st;

        for(int i = m - 1; i >= 0; i--) {
            while(!st.empty() && nums2[i] > st.top()) {
                st.pop();
            }

            if(st.empty()) {
                next[i] = -1;
            } else {
                next[i] = st.top();
            }

            st.push(nums2[i]);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j]) {
                    ans[i] = next[j];
                }
            }
        }

        return ans;
    }
};