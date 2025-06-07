// Last updated: 6/7/2025, 5:39:28 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int st = 0;
        int end = n-1;

        if(n == 1) {
            return nums[0];
        }
        if(nums[0] < nums[n-1]) return nums[0];

        while(st < end) {

            int mid = st + (end-st)/2;

            if(nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end = mid;
            }

            // if(mid == 0 && nums[mid] < nums[mid+1]) {
            //     return nums[mid];
            // }

            // if(mid == n-1 && nums[mid] < nums[mid-1]) {
            //     return nums[mid];
            // }

            // if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) {
            //     return nums[mid];
            // }

            // if(nums[mid] < nums[mid-1]) {
            //     end = mid - 1; 
            // } else {
            //     st = mid + 1;
            // }
        }

        return nums[st];
    }
};