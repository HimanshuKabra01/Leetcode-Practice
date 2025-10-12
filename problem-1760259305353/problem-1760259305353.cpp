// Last updated: 10/12/2025, 2:25:05 PM
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        for(auto &entry : m) {
            if(entry.second % k == 0) {
                sum += (entry.first*entry.second);
            }
        }

        return sum;
    }
};