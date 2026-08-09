// Last updated: 8/9/2026, 12:30:50 PM
class Solution {
public:
    int maxProduct(int n) {
        vector<int> digs;

        while(n > 0) {
            int dig = n % 10;

            digs.push_back(dig);

            n /= 10;
        }

        sort(digs.begin(), digs.end());

        return digs[digs.size()-1] * digs[digs.size()-2];
    }
};