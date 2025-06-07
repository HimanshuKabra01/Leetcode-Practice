// Last updated: 6/7/2025, 5:39:43 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find pivot
        int n = nums.size();
        int pivot = -1;

        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //find rightmost element

        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //reverse the rest of the array

        int i = pivot + 1;
        int j = n - 1;

        while(i <= j) {
            swap(nums[i++], nums[j--]);
        }
        
    }
};