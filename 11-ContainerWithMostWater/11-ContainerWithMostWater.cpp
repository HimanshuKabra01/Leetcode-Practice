// Last updated: 7/15/2025, 8:54:24 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        //  BRUTE APPROACH
        // int currArea, maxArea = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         currArea = min(height[i], height[j])*(j-i);
        //         maxArea = max(currArea, maxArea);
        //     }
        // }
        // return maxArea;
        int i = 0, j = n - 1;
        int maxArea = 0;
        while (i < j) {
            int ht = min(height[i], height[j]);
            int currArea = ht*(j-i);
            maxArea = max(maxArea, currArea);
            if(height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};