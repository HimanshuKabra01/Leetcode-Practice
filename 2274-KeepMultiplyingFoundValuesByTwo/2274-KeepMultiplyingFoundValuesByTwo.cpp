// Last updated: 8/9/2026, 12:32:11 PM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        while(s.find(original) != s.end()) {
            original = 2*original;
        }

        return original;
    }
};