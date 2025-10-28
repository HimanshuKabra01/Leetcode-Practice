// Last updated: 10/28/2025, 4:51:28 PM
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