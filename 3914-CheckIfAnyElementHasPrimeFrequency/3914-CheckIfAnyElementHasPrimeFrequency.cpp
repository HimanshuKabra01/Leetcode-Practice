// Last updated: 8/9/2026, 12:30:46 PM
class Solution {
public:
    bool prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int freq = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                freq++;
            } else {
                if (prime(freq)) return true;
                freq = 1;
            }
        }

        // Check the last group
        if (prime(freq)) return true;

        return false;
    }
};
