// Last updated: 1/2/2026, 12:16:28 PM
1    class Solution {
2    public:
3        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4            int m = nums1.size();
5            int n = nums2.size();
6
7            if(m+n == 0) {
8                return 0;
9            }
10
11            vector<int> merged;
12            double median = 0;
13            int i = 0;
14            int j = 0;
15
16            while(i < m && j < n) {
17                if(nums1[i] <= nums2[j]) {
18                    merged.push_back(nums1[i]);
19                    i++;
20                } else {
21                    merged.push_back(nums2[j]);
22                    j++;
23                }
24            }
25
26            while(i < m) {
27                merged.push_back(nums1[i]);
28                i++;
29            }
30
31            while(j < n) {
32                merged.push_back(nums2[j]);
33                j++;
34            }
35
36            int st = 0;
37            int end = m + n;
38
39            int mid = st + (end-st)/2;
40
41            if((m+n) % 2 != 0) {
42                median = merged[mid];
43            } else {
44                median = (merged[mid-1] + merged[mid])/2.0;
45            }
46
47            return median;
48        }
49    };