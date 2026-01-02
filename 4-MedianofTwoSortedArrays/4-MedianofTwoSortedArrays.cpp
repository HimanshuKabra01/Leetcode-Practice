// Last updated: 1/2/2026, 12:28:23 PM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        //O(m+n)
5        // int m = nums1.size();
6        // int n = nums2.size();
7
8        // if(m+n == 0) {
9        //     return 0;
10        // }
11
12        // vector<int> merged;
13        // double median = 0;
14        // int i = 0;
15        // int j = 0;
16
17        // while(i < m && j < n) {
18        //     if(nums1[i] <= nums2[j]) {
19        //         merged.push_back(nums1[i]);
20        //         i++;
21        //     } else {
22        //         merged.push_back(nums2[j]);
23        //         j++;
24        //     }
25        // }
26
27        // while(i < m) {
28        //     merged.push_back(nums1[i]);
29        //     i++;
30        // }
31
32        // while(j < n) {
33        //     merged.push_back(nums2[j]);
34        //     j++;
35        // }
36
37        // int st = 0;
38        // int end = m + n;
39
40        // int mid = st + (end-st)/2;
41
42        // if((m+n) % 2 != 0) {
43        //     median = merged[mid];
44        // } else {
45        //     median = (merged[mid-1] + merged[mid])/2.0;
46        // }
47
48        // return median;
49
50        //O(log(m+n));
51        if (nums1.size() > nums2.size()) {
52            return findMedianSortedArrays(nums2, nums1);
53        }
54
55        int m = nums1.size();
56        int n = nums2.size();
57        int low = 0, high = m;
58
59        while (low <= high) {
60            int partitionX = (low + high) / 2;
61            int partitionY = (m + n + 1) / 2 - partitionX;
62
63            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
64            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
65
66            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
67            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
68
69            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
70                if ((m + n) % 2 == 0) {
71                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
72                } else {
73                    return max(maxLeftX, maxLeftY);
74                }
75            } else if (maxLeftX > minRightY) {
76                high = partitionX - 1;
77            } else {
78                low = partitionX + 1;
79            }
80        }
81        return 0.0;
82    }
83};