// Last updated: 8/21/2026, 12:41:25 AM
1class Solution {
2public:
3    void dfs(string curr, vector<string> &ans, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adj) {
4        while(!adj[curr].empty()) {
5            string next = adj[curr].top();
6            adj[curr].pop();
7
8            dfs(next, ans, adj);
9        }
10
11        ans.push_back(curr);
12    }
13    vector<string> findItinerary(vector<vector<string>>& tickets) {
14        vector<string> ans;
15        int n = tickets.size();
16
17        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
18
19        for(int i = 0; i < n; i++) {
20            adj[tickets[i][0]].push(tickets[i][1]);
21        }
22
23        dfs("JFK", ans, adj);
24
25        reverse(ans.begin(), ans.end());
26
27        return ans;             
28    }
29};