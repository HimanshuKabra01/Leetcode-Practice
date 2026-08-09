// Last updated: 8/9/2026, 12:30:41 PM
class Solution {
public:
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;

        for(int i = 1; i <= n*2; i++) {
            if(i % 2 == 0) {
                sumEven += i;
            } else {
                sumOdd += i;
            }
        }

        return gcd(sumOdd, sumEven);
    }
};