// Last updated: 6/17/2026, 5:23:06 PM
1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
4        int n = wordList.size();
5
6        set<string> st;
7        for(int i = 0; i < n; i++) {
8            st.insert(wordList[i]);
9        }
10
11        if(st.find(endWord) == st.end()) {
12            return 0;
13        }
14
15        queue<pair<string, int>> q;
16        q.push({beginWord, 1});
17
18        while(!q.empty()) {
19            string curr = q.front().first;
20            int lev = q.front().second;
21            
22            q.pop();
23            for(int i = 0; i < curr.size(); i++) {
24                char original = curr[i];
25                for(int j = 0; j < 26; j++) {
26                    curr[i] = 'a' + j;
27
28                    if(curr == endWord) {
29                        return lev+1;
30                    }
31                    else if(st.find(curr) != st.end()) {
32                        q.push({curr, lev+1});
33                        st.erase(curr);
34                    }
35                }
36
37                curr[i] = original;
38            }
39        }
40
41        return 0;
42    }
43};