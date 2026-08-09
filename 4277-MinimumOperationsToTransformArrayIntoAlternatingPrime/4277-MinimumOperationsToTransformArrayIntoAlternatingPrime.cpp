// Last updated: 8/9/2026, 12:28:30 PM
class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n <= 3) return true;

        if(n % 2 == 0 || n % 3 == 0) return false;

        for(int i = 5; i*i <= n; i += 6) {
            if(n % i == 0 || n % (i+2) == 0) {
            return false;
            }
        }

        return true;
    }
    int minOperations(vector<int>& a) {
        int n = a.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 != 0) {
                if(!isPrime(a[i])) continue;
                else {
                    if(a[i] == 2) {
                        ans += 2;
                    } else if(a[i] == 1) {
                        ans += 3;
                    } else {
                        ans++;
                    }
                }
            } else {
                if(isPrime(a[i])) continue;
                else {
                    while(!isPrime(a[i])) {
                        a[i]++;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};