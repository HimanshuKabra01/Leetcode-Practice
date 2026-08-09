// Last updated: 8/9/2026, 12:37:32 PM
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long maxNum = LLONG_MIN;
        long long secLar = LLONG_MIN;
        long long thirdMax = LLONG_MIN;

        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return nums[1];
        }

        for(int num : nums) {
            if(num > maxNum) {
                thirdMax = secLar;
                secLar = maxNum;
                maxNum = num;
            } else if(num > secLar && num != maxNum) {
                thirdMax = secLar;
                secLar = num;
            } else if(num > thirdMax && num != maxNum && num != secLar) {
                thirdMax = num;
            }
        }

        return (thirdMax == LLONG_MIN ? maxNum : thirdMax);
    }
};