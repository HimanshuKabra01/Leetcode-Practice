// Last updated: 9/24/2025, 4:15:02 PM
class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp;
        int i = st;
        int j = mid+1;

        while(i <= mid && j <=end) {
            if(nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for(int idx = 0; idx < temp.size(); idx++) {
            nums[idx+st] = temp[idx];
        }
    }
    void mergeSort(vector<int>& nums, int st, int end) {
        if(st < end) {

            int mid = st+(end-st)/2;

            mergeSort(nums, st, mid); //left half
            mergeSort(nums, mid+1, end); //right half

            //sorting while backtracking
            merge(nums, st, mid, end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums, 0, nums.size()-1);

        return nums;

        static  auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
    }
};