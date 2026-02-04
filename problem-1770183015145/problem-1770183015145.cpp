// Last updated: 2/4/2026, 11:00:15 AM
1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> arr;
7        for(int i = 0; i < n-1; i++) {
8            int diff = nums[i+1] - nums[i];
9
10            arr.push_back(diff);
11        }
12
13        int m = arr.size();
14        int p = -1;
15        int q = -1;
16
17        for(int i = 0; i < m; i++) {
18            if(arr[i] < 0) {
19                p = i;
20                break;
21            }
22        }
23
24        for(int i = p+1; i < m; i++) {
25            if(arr[i] > 0) {
26                q = i;
27                break;
28            }
29        }
30
31        if(p <= 0 || q == -1) {
32            return false;
33        }
34
35        bool possible = true;
36        for(int i = 0; i < p; i++) {
37            if(arr[i] <= 0) {
38                possible = false;
39            }
40        }
41
42        for(int i = p; i < q; i++) {
43            if(arr[i] >= 0) {
44                possible = false;
45            }
46        }
47
48        for(int i = q; i < m; i++) {
49            if(arr[i] <= 0) {
50                possible = false;
51            }
52        }
53
54        return possible;
55    }
56};