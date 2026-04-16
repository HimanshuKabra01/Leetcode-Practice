// Last updated: 4/17/2026, 1:48:28 AM
1class Solution {
2public:
3    bool isHappy(int n) {
4        int sum = 0;
5       while(n != 0) {
6            while(n > 0) {
7                int digit = n % 10;
8
9                sum += digit*digit;
10
11                n /= 10;
12            }
13
14            if(sum == 1) {
15                return true;
16                break;
17            }
18            n = sum;
19            if(n == 2 || n ==3 || n == 4 || n == 5 || n==6 || n==8 || n==9) {
20            return false;
21        }
22            sum = 0;
23       }
24
25       return false; 
26    }
27};