// Last updated: 10/4/2025, 11:20:57 AM
class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();

      int i = 0, j = n - 1;
      int maxArea = 0;

      while(i < j) {
        int ht = min(height[i], height[j]);
        int width = j - i;
        int currArea = ht*width;

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