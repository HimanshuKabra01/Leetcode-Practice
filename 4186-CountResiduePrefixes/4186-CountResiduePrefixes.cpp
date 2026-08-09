// Last updated: 8/9/2026, 12:29:20 PM
class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> st;
        int ans = 0;
        int n = s.size();

        string prefix = "";
        int dist = 0;

        for(int i = 0; i < n; i++) {
            prefix += s[i];

            if(st.find(s[i]) == st.end()) {
                dist++;

                st.insert(s[i]);
            }

            int resi = (prefix.size() % 3);

            if(dist == resi) {
                ans++;
            }
        }

        return ans;
    }
};