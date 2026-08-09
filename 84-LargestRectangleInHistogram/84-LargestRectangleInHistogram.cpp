// Last updated: 8/9/2026, 12:41:35 PM
class Solution {
public:
    void getWidth(vector<int> &heights, vector<int> &width) {
        int n = heights.size();
        stack<int> st;

        vector<int> right;
        vector<int> left;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                left.push_back(-1);
            } else {
                left.push_back(st.top());
            }

            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                right.push_back(n);
            } else {
                right.push_back(st.top());
            }

            st.push(i);
        }

        reverse(right.begin(), right.end());

        for(int i = 0; i < n; i++) {
            width[i] = right[i] - left[i] - 1;
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> width(n);
        int ans = 0;

        getWidth(heights, width);

        for(int i = 0; i < n; i++) {
            int currArea = heights[i]*width[i];

            ans = max(currArea, ans);
        }

        return ans;
    }
};