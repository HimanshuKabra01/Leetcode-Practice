// Last updated: 8/9/2026, 12:37:38 PM
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        int n = s.size();
        queue<pair<char, int>> q;
        int ans = -1;

        for(int i = 0; i < n; i++) {
            m[s[i]]++;
            q.push({s[i], i});
        }

        while(!q.empty()) {
            if(m[q.front().first] == 1) {
                ans = q.front().second;
                break;
            }

            q.pop();
        }

        return ans;
    }
};