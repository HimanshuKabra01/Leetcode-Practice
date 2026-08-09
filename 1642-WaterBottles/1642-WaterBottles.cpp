// Last updated: 8/9/2026, 12:33:03 PM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drankBottles = numBottles;
        int leftBottles = 0;

        while(numBottles >= numExchange || numBottles+leftBottles >= numExchange ) {
            int n = (numBottles+leftBottles)/numExchange;
            int bottlesUsed = n * numExchange;
            leftBottles = (numBottles+leftBottles) % numExchange;

            drankBottles += n;
            numBottles = n;
        }

        return drankBottles;
    }
};