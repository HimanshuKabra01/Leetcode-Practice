// Last updated: 8/9/2026, 12:34:14 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        int ans = 0;
        while(pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x != y) {
                pq.push(y - x);
            }
        }

        if(pq.size() == 0) {
            return 0;
        } else {
            return pq.top();
        }
    }
};