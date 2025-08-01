// Last updated: 6/7/2025, 5:39:17 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n-1;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                end = mid-1;
            } else if(nums[mid] < target) {
                st = mid + 1;
            }
        }

        return -1;
    }
};