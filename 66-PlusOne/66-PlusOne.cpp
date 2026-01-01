// Last updated: 1/1/2026, 9:59:57 AM
1class Solution {
2public:
3    std::vector<int> plusOne(std::vector<int>& digits) {
4        int n = digits.size();
5
6        for (int i = n - 1; i >= 0; i--) {
7            digits[i]++;
8
9            if (digits[i] < 10) {
10                return digits;
11            }
12            digits[i] = 0;
13        }
14        digits.insert(digits.begin(), 1);
15        return digits;
16    }
17};