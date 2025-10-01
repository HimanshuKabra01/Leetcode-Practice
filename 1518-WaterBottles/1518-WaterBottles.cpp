// Last updated: 10/1/2025, 8:11:46 PM
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