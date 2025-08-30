// Last updated: 8/31/2025, 1:04:27 AM
class Solution {
public:
    int fibonacci(int n){
        if(n == 0 || n == 1) {
            return n;
        }

        return fibonacci(n-1) + fibonacci(n-2);
    }
    int fib(int n) {
        int val = fibonacci(n);

        return val;
    }
};