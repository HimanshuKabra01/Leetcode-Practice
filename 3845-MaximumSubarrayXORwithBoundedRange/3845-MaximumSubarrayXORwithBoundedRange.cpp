// Last updated: 2/15/2026, 11:28:59 AM
1class Solution {
2public:
3    int firstUniqueFreq(vector<int>& nums) {
4        unordered_map<int, int> m;
5
6        for(int i = 0; i < nums.size(); i++) {
7            m[nums[i]]++;
8        }
9
10        unordered_map<int, int> freq;
11
12        for(auto &entry : m) {
13            freq[entry.second]++;
14        }
15
16        for(int i = 0; i < nums.size(); i++) {
17            if(freq[m[nums[i]]] == 1) {
18                return nums[i];
19            } 
20        }
21
22        return -1;
23    }
24};