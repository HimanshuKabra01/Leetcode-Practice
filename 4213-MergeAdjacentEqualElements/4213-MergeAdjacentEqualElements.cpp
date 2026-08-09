// Last updated: 8/9/2026, 12:29:02 PM
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        stack<long long> st;

        int i = 0;
        while(i != nums.size()) {
            if(st.empty()) {
                st.push(nums[i]);
                i++;
                continue;
            }

            if(st.top() == nums[i]) {
                long long curr = nums[i];

                while(!st.empty() && st.top() == curr) {
                    st.pop();

                    curr *= 2;
                }

                st.push(curr);
            } else {
                st.push(nums[i]);
            }

            i++;
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};