// Last updated: 11/17/2025, 10:02:25 AM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int left = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {

                if(left != -1 && (i - left - 1) < k) {
                    return false;
                }

                left = i;
            }
        }

        return true;
    }
};