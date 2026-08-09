// Last updated: 8/9/2026, 12:34:48 PM
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