// Last updated: 8/9/2026, 12:32:26 PM
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