// Last updated: 8/9/2026, 12:30:07 PM
class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;

        for(int k = 1; k <= n; k++) {
            string s1 = s;
            string s2 = s;

            reverse(s1.begin(), s1.begin()+k);
            reverse(s2.end()-k, s2.end());
            
            ans = min(ans, min(s1, s2));
        };

        return ans;
    }
};