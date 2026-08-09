// Last updated: 8/9/2026, 12:28:45 PM
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> a(10);

        a[0] = 1;
        int curr = 1;
        for(int i = 1; i <= 9; i++) {
            curr *= i;

            a[i] = curr;
        }

        unordered_set<string> s;
        string num = to_string(n);

        sort(num.begin(), num.end());

        do {
            s.insert(num);
        } while(next_permutation(num.begin(), num.end()));

        int sum = 0;

        while(n > 0) {
            int dig = n % 10;

            sum += a[dig];

            n /= 10;
        }

        string ans = to_string(sum);

        return s.find(ans) != s.end();
    }
};