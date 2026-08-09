// Last updated: 8/9/2026, 12:35:59 PM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        vector<int> idx(26, INT_MIN);

        for(int i = 0; i < n ; i++) {
            if(i > idx[s[i]-'a']) {
                idx[s[i]-'a'] = i;
            }
        }
        
        int end = 0;
        int prevEnd = 0;
        for(int i = 0; i < n; i++) {
            if(idx[s[i]-'a'] > end) {
                end = idx[s[i]-'a'];
            }

            if(i == end) {
                ans.push_back(end+1-prevEnd);
                prevEnd = end+1;
            }
        }

        return ans;
    }
};