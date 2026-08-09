// Last updated: 8/9/2026, 12:36:38 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();

        map<char, int> mp;

        for(int i = 0; i < sz; i++) {
            mp[tasks[i]]++;
        }

        priority_queue<int> pq;
        queue<pair<int, int>> q;   
        for(auto &entry : mp) {
            pq.push(entry.second);
        }

        int ans = 0;

        while(!pq.empty() || !q.empty()) {
            if(!q.empty()) {
                int count = q.front().first;
                int time = q.front().second;
    
                if(ans == time) {
                    pq.push(count);
                    q.pop();
                }
            } 

            if(!pq.empty()) {
                int count = pq.top();
                pq.pop();

                if(count-1>0) {
                    q.push({count-1, ans+n+1});
                }
            }
            
            ans++;
        }

        return ans;
    }
};