// Last updated: 8/29/2025, 11:38:28 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        int num = nums[0];
        int freq = 0;
        for(int i = 0; i < n; i++) {
            if(num == nums[i]) {
                freq++;
            } else{
                freq = 1;
                num = nums[i];
            }

            if(freq == 1 || freq == 2) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};