// Last updated: 7/21/2025, 11:52:40 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //BRUTE FORCE O(nlogn)
        //sort(nums.begin(), nums.end());

        //Optimized

        int n = nums.size();
        // int count0 = 0, count1 = 0, count2 = 0;

        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == 0) {
        //         count0++;
        //     } else if(nums[i] == 1) {
        //         count1++;
        //     } else {
        //         count2++;
        //     }
        // }

        // int idx = 0;

        // for(int i = 0; i < count0; i++) {
        //     nums[idx++] = 0;
        // }
        // for(int i = 0; i < count1; i++) {
        //     nums[idx++] = 1;
        // }
        // for(int i = 0; i < count2; i++) {
        //     nums[idx++] = 2;
        // }

        //More Optimized

        int low = 0; 
        int mid = 0;
        int high = n - 1;

        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};