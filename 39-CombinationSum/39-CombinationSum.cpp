// Last updated: 9/25/2025, 7:15:15 PM
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            digits[i]++;

            if (digits[i] < 10) {
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};