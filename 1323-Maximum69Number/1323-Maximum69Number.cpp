// Last updated: 8/16/2025, 3:22:24 PM
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        vector<int> digits;
        int maxNum = 0;

        for(char c : s) {
            digits.push_back(c - '0');
        }

        int n = digits.size();

        for(int i = 0; i < n; i++) {
            if(digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }

        for(int d : digits) {
            maxNum = maxNum * 10 + d;
        }

        return maxNum;
    }
};