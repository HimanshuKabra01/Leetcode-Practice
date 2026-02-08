// Last updated: 2/8/2026, 2:27:47 PM
1class Solution {
2public:
3    vector<long long> mergeAdjacent(vector<int>& nums) {
4        vector<long long> ans;
5        stack<long long> st;
6
7        int i = 0;
8        while(i != nums.size()) {
9            if(st.empty()) {
10                st.push(nums[i]);
11                i++;
12                continue;
13            }
14
15            if(st.top() == nums[i]) {
16                long long curr = nums[i];
17
18                while(!st.empty() && st.top() == curr) {
19                    st.pop();
20
21                    curr *= 2;
22                }
23
24                st.push(curr);
25            } else {
26                st.push(nums[i]);
27            }
28
29            i++;
30        }
31
32        while(!st.empty()) {
33            ans.push_back(st.top());
34            st.pop();
35        }
36
37        reverse(ans.begin(), ans.end());
38
39        return ans;
40    }
41};