// Last updated: 6/7/2025, 5:39:26 PM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = nums.size()-1;

        while(st < end) {
            int mid = st + (end-st)/2;

            if(nums[mid] > nums[mid+1]) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }

        return st;
    }
};