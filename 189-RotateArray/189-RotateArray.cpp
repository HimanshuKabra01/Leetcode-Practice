// Last updated: 8/7/2025, 7:45:14 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int num = k % n;

        reverse(nums.begin() + (n-num), nums.end());

        reverse(nums.begin(), nums.begin() + (n-num));

        reverse(nums.begin(), nums.end());
    }
};