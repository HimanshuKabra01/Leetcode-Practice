// Last updated: 8/9/2026, 12:28:59 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";

        for(int i = 0; i < n; i++) {
            string s = words[i];
            int sum = 0;

            for(int j = 0; j < s.size(); j++) {
                sum += weights[s[j] - 'a'];
            }

            int wm = sum % 26;

            ans += 'z' - wm;
        }

        return ans;
    }
};