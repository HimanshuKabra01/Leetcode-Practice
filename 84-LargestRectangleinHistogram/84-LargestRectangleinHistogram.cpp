// Last updated: 1/9/2026, 11:41:38 AM
1class Solution {
2public:
3    void getWidth(vector<int> &heights, vector<int> &width) {
4        int n = heights.size();
5        stack<int> st;
6
7        vector<int> right;
8        vector<int> left;
9
10        for(int i = 0; i < n; i++) {
11            while(!st.empty() && heights[st.top()] >= heights[i]) {
12                st.pop();
13            }
14
15            if(st.empty()) {
16                left.push_back(-1);
17            } else {
18                left.push_back(st.top());
19            }
20
21            st.push(i);
22        }
23
24        while(!st.empty()) {
25            st.pop();
26        }
27
28        for(int i = n-1; i >= 0; i--) {
29            while(!st.empty() && heights[st.top()] >= heights[i]) {
30                st.pop();
31            }
32
33            if(st.empty()) {
34                right.push_back(n);
35            } else {
36                right.push_back(st.top());
37            }
38
39            st.push(i);
40        }
41
42        reverse(right.begin(), right.end());
43
44        for(int i = 0; i < n; i++) {
45            width[i] = right[i] - left[i] - 1;
46        }
47    }
48
49    int largestRectangleArea(vector<int>& heights) {
50        int n = heights.size();
51        vector<int> width(n);
52        int ans = 0;
53
54        getWidth(heights, width);
55
56        for(int i = 0; i < n; i++) {
57            int currArea = heights[i]*width[i];
58
59            ans = max(currArea, ans);
60        }
61
62        return ans;
63    }
64};