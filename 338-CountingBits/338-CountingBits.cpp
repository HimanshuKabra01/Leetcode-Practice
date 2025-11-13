// Last updated: 11/13/2025, 11:01:38 AM
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i = 1; i <= n; i++) {
            unordered_map<int, int> m;
            int num = i;

            while(num >= 1) {
                int dig = num % 2;

                m[dig]++;

                num /= 2;
            }

            ans[i] = m[1];
        }

        return ans;
    }
};