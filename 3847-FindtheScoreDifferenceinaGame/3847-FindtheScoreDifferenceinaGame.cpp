// Last updated: 2/22/2026, 5:32:34 PM
1class Solution {
2public:
3    bool isDigitorialPermutation(int n) {
4        vector<int> a(10);
5
6        a[0] = 1;
7        int curr = 1;
8        for(int i = 1; i <= 9; i++) {
9            curr *= i;
10
11            a[i] = curr;
12        }
13
14        unordered_set<string> s;
15        string num = to_string(n);
16
17        sort(num.begin(), num.end());
18
19        do {
20            s.insert(num);
21        } while(next_permutation(num.begin(), num.end()));
22
23        int sum = 0;
24
25        while(n > 0) {
26            int dig = n % 10;
27
28            sum += a[dig];
29
30            n /= 10;
31        }
32
33        string ans = to_string(sum);
34
35        return s.find(ans) != s.end();
36    }
37};