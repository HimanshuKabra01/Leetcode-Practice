// Last updated: 8/9/2026, 12:43:24 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //O(m+n)
        // int m = nums1.size();
        // int n = nums2.size();

        // if(m+n == 0) {
        //     return 0;
        // }

        // vector<int> merged;
        // double median = 0;
        // int i = 0;
        // int j = 0;

        // while(i < m && j < n) {
        //     if(nums1[i] <= nums2[j]) {
        //         merged.push_back(nums1[i]);
        //         i++;
        //     } else {
        //         merged.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while(i < m) {
        //     merged.push_back(nums1[i]);
        //     i++;
        // }

        // while(j < n) {
        //     merged.push_back(nums2[j]);
        //     j++;
        // }

        // int st = 0;
        // int end = m + n;

        // int mid = st + (end-st)/2;

        // if((m+n) % 2 != 0) {
        //     median = merged[mid];
        // } else {
        //     median = (merged[mid-1] + merged[mid])/2.0;
        // }

        // return median;

        //O(log(m+n));
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        return 0.0;
    }
};