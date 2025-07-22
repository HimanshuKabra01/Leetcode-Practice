// Last updated: 7/22/2025, 8:25:47 PM
class Solution {
public:
    int countPrimes(int n) {
        // int count = 0;

        // for(int i = 2; i < n; i++) {
        //     bool isPrime = true;
        //     for(int j = 2; j*j <= i; j++) {
        //         if(i % j == 0) {
        //             isPrime = false;
        //             break;
        //         }
        //     }

        //     if(isPrime) {
        //         count++;
        //     }
        // }

        // return count;

        vector<bool> isPrime(n+1, true);
        int count = 0;

        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                count++;

                for(int j = i * 2; j < n; j = i + j) {
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};