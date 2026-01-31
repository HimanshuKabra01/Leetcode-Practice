// Last updated: 1/31/2026, 3:32:18 PM
1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int n = letters.size();
5
6        char ans = letters[0];
7
8        int st = 0;
9        int end = n - 1;
10
11        while(st <= end) {
12            int mid = st + (end-st)/2;
13
14            if(letters[mid] <= target) {
15                st = mid + 1;
16            } else {
17                end = mid - 1;
18                ans = letters[mid];
19            }
20        }
21
22        return ans;
23    }
24};