// Last updated: 6/7/2025, 5:39:22 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int suffix = 1;
        vector<int> ans(n, 1);

        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix; 
        }


        return ans;
    }
};