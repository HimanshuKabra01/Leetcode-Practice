// Last updated: 11/23/2025, 10:11:27 AM
class Solution {
public:
    long long sumAndMultiply(int n) {
        
        if(n == 0) {
            return 0;
        }

        string s = to_string(n);
        string noZero = "";
        int size = s.size();

        for(int i = 0; i < size; i++) {
            if(s[i] != '0') {
                noZero += s[i];
            }
        }

        long long num = stoll(noZero);
        long long num2 = num;
        long long sum = 0;

        while(num2 > 0) {
            int dig = num2 % 10;

            sum += dig;

            num2 /= 10;
        }

        long long ans = num * sum;

        return ans;
    }
};