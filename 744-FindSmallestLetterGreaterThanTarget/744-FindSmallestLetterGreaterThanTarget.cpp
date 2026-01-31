// Last updated: 1/31/2026, 3:24:58 PM
1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int n = letters.size();
5
6        char ans = letters[0];
7
8        for(int i = 0; i < n; i++) {
9            if(letters[i] > target) {
10                ans = letters[i];
11                break;
12            }
13        }
14
15        return ans;
16    }
17};