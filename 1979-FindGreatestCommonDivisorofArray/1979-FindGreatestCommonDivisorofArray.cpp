// Last updated: 7/19/2026, 1:02:43 AM
1class Solution {
2public:
3    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
4    int findGCD(vector<int>& nums) {
5        sort(nums.begin(), nums.end());
6
7        return gcd(nums[0], nums.back());
8    }
9};