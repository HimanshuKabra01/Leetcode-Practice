// Last updated: 7/11/2025, 5:20:31 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currProduct = 1;
        int maxProduct = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            currProduct *= nums[i];
            maxProduct = max(currProduct, maxProduct);
            
            if(currProduct == 0) {
                currProduct = 1;
            }
        }
        currProduct = 1;
        for(int i = n-1; i >= 0; i--) {
            currProduct *= nums[i];
            maxProduct = max(currProduct, maxProduct);

            if(currProduct == 0) {
                currProduct = 1;
            }
        }

        return maxProduct;
    }
};