// Last updated: 7/16/2026, 12:54:05 AM
1class Solution {
2public:
3    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
4    int gcdOfOddEvenSums(int n) {
5        int sumOdd = 0;
6        int sumEven = 0;
7
8        for(int i = 1; i <= n*2; i++) {
9            if(i % 2 == 0) {
10                sumEven += i;
11            } else {
12                sumOdd += i;
13            }
14        }
15
16        return gcd(sumOdd, sumEven);
17    }
18};