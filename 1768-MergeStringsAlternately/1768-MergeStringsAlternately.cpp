// Last updated: 1/5/2026, 11:43:48 PM
1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        string ans = "";
5        int n1 = word1.size();
6        int n2 = word2.size();
7
8        int i = 0;
9        while(i < n1 && i < n2) {
10            ans += word1[i];
11            ans += word2[i];
12
13            i++;
14        }
15
16        while(i < n1) {
17            ans += word1[i];
18
19            i++;
20        }
21
22        while(i < n2) {
23            ans += word2[i];
24
25            i++;
26        }
27
28        return ans;
29    }
30};