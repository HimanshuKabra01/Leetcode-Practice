// Last updated: 8/9/2026, 12:34:47 PM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        int n = points.size();

        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        for(int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            double dist = sqrt(x*x + y*y);

            pq.push({dist, points[i]});
        }

        int count = 0;
        while(!pq.empty()) {
            vector<int> req = pq.top().second;
            pq.pop();

            count++;

            if(count == k) {
                ans.push_back(req);
                break;
            }

            ans.push_back(req);
        }

        return ans;
    }
};