// Last updated: 8/31/2025, 10:30:21 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int num;

        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < n){
            if(nums[i] != i){
                num = i;
                break;
            }

            i++;
        }

        return num;
    }
};