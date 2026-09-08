// Last updated: 9/9/2026, 1:37:45 AM
1class Solution {
2public:
3    void getCombin(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combin,int i, int target) {
4        int n = candidates.size();
5
6        if(target == 0) {
7            ans.push_back({combin});
8            return;
9        }
10
11        if(i == n || target < 0) {
12            return;
13        }
14
15        combin.push_back(candidates[i]);
16        getCombin(candidates, ans, combin, i + 1, target - candidates[i]);
17        combin.pop_back();
18
19        while(i+1 < n && candidates[i] == candidates[i+1]) {
20            i++;
21        }
22        
23        getCombin(candidates, ans, combin, i + 1, target);
24    }   
25
26    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
27        sort(candidates.begin(), candidates.end());
28        vector<vector<int>> ans;
29        vector<int> combin;
30
31        getCombin(candidates, ans, combin, 0, target);
32
33        return ans;
34    }
35};