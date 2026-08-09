// Last updated: 8/9/2026, 12:32:45 PM
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;

        for(int i = 1; i <= n; i++) {
            friends.push_back(i);
        }

        int size = friends.size();
        int st = 0;
        while(size > 1) {
            int idx = (st + k - 1) % size;

            friends.erase(friends.begin() + idx);
            st = idx;

            size = friends.size();
        }

        return friends[0];
    }
};