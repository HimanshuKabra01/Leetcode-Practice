// Last updated: 8/9/2026, 12:38:53 PM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> pq;

        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }
        int count = 0;
        int ans = 0;

        while(!pq.empty()) {
            int num = pq.top();

            pq.pop();
            count++;

            if(count == k) {
                ans = num;
                break;
            }
        }

        return ans;
    }
};