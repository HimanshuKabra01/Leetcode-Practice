// Last updated: 8/9/2026, 12:31:36 PM
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drankBottles = numBottles;
        int readyBottles = 0;

        while(numBottles >= numExchange) {
            numBottles -= numExchange;
            readyBottles++;
            numExchange++;
        }

        drankBottles += readyBottles;

        if((numBottles+readyBottles >= numExchange)) {
            drankBottles++;
        }

        return drankBottles;
    }
};