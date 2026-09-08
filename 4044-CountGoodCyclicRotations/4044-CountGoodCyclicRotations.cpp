// Last updated: 9/8/2026, 4:32:10 PM
1class Solution {
2public:
3    int countGoodRotations(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> a;
7        vector<int> b;
8
9        for(int i = 0; i < n/2; i++) {
10            a.push_back(nums[i]);
11        }
12
13        for(int i = n/2; i < n; i++) {
14            b.push_back(nums[i]);
15        }
16
17        long long s1 = 0;
18        long long s2 = 0;
19
20        for(int i = 0; i < a.size(); i++) {
21            s1 += a[i];
22            s2 += b[i];
23        }
24
25        int c = 0;
26        int d = 0;
27
28        int ans = 0;
29
30        if(s1 != s2) {
31            ans++;
32        }
33
34        while(c < a.size()-1 && d < b.size()-1) {
35            s1 -= a[c];
36            s1 += b[d];
37
38            s2 -= b[d];
39            s2 += a[c];
40
41            if(s1 != s2) {
42                ans++;
43            }
44
45            c++;
46            d++;
47        }
48
49        return ans;
50    }
51};