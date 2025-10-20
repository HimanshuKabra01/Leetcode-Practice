// Last updated: 10/20/2025, 10:15:18 AM
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();

        int x = 0;

        for(int i = 0; i < n; i++) {
            if(operations[i] == "++X" || operations[i] == "X++") {
                x++;
            } else if(operations[i] == "--X" || operations[i] == "X--") {
                x--;
            }
        }

        return x;
    }
};