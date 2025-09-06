// Last updated: 9/6/2025, 10:06:33 AM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int misNum = 1;

        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) continue;

            s.insert(nums[i]);
        }

        if(s.empty()) return 1;

        for(int i = 1; i <= nums[n-1]; i++) {
            if(s.find(i) == s.end()) {
                return i;
            }
        }

        return nums[n-1]+1;
    }
};