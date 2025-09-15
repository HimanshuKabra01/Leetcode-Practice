// Last updated: 9/15/2025, 11:36:12 PM
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int avg = round(sum / n);

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) continue;

            s.insert(nums[i]);
        }

        if(s.empty()) return 1;

        if(avg < 0) avg = 0;

        for(int i = avg+1; i < nums[n-1]; i++) {
            if(s.find(i) == s.end()) {
                return i;
            }
        }

        return nums[n-1]+1;
    }
};