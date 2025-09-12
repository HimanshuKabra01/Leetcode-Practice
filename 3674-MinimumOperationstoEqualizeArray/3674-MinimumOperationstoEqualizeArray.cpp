// Last updated: 9/12/2025, 10:39:08 PM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) {
            return 0;
        }

        int target = nums[0];
        for(int i = 0; i < n; i++) {
            target &= nums[i];
        }

        for(int i = 0; i < n; i++) {
            if(target != nums[i]) {
                return 1;
            }
        }

        return 0;
    }
};