// Last updated: 12/24/2025, 7:05:41 PM
1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        int n = apple.size();
5        int ans = 0;
6        int sum = 0;
7
8        sort(capacity.rbegin(), capacity.rend());
9
10        for(int i = 0; i < n; i++) {
11            sum += apple[i];
12        }
13
14        for(int i = 0; i < capacity.size(); i++) {
15            ans++;
16            sum -= capacity[i];
17
18            if(sum <= 0) {
19                break;
20            }
21        }
22
23        return ans;
24    }
25};