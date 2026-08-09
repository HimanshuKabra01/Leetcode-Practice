// Last updated: 8/9/2026, 12:31:37 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int ans = 0;
        int sum = 0;

        sort(capacity.rbegin(), capacity.rend());

        for(int i = 0; i < n; i++) {
            sum += apple[i];
        }

        for(int i = 0; i < capacity.size(); i++) {
            ans++;
            sum -= capacity[i];

            if(sum <= 0) {
                break;
            }
        }

        return ans;
    }
};