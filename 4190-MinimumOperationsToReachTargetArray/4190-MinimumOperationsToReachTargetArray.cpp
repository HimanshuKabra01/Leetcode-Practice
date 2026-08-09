// Last updated: 8/9/2026, 12:29:18 PM
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            if(nums[i] != target[i]) {
                s.insert(nums[i]);
            }
        }

        return s.size();
    }
};