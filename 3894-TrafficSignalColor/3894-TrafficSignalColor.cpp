// Last updated: 4/13/2026, 1:08:12 AM
1class Solution {
2public:
3    bool isPrime(int n) {
4        if(n <= 1) return false;
5        if(n <= 3) return true;
6
7        if(n % 2 == 0 || n % 3 == 0) return false;
8
9        for(int i = 5; i*i <= n; i += 6) {
10            if(n % i == 0 || n % (i+2) == 0) {
11            return false;
12            }
13        }
14
15        return true;
16    }
17    int minOperations(vector<int>& a) {
18        int n = a.size();
19
20        int ans = 0;
21        for(int i = 0; i < n; i++) {
22            if(i % 2 != 0) {
23                if(!isPrime(a[i])) continue;
24                else {
25                    if(a[i] == 2) {
26                        ans += 2;
27                    } else if(a[i] == 1) {
28                        ans += 3;
29                    } else {
30                        ans++;
31                    }
32                }
33            } else {
34                if(isPrime(a[i])) continue;
35                else {
36                    while(!isPrime(a[i])) {
37                        a[i]++;
38                        ans++;
39                    }
40                }
41            }
42        }
43
44        return ans;
45    }
46};