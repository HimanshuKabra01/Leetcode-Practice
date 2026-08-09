// Last updated: 8/9/2026, 12:32:28 PM
class Solution {
public:
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return gcd(nums[0], nums.back());
    }
};