// Last updated: 6/7/2025, 5:39:18 PM
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1;
        int end = arr.size()-2;

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            }

            if(arr[mid-1] > arr[mid]) {//we'll go into right half
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }
};