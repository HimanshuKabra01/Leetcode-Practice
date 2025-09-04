// Last updated: 9/4/2025, 7:59:45 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(x == y) return 0;
        else if(x <= y && y <= z) return 2;
        else if(z <= y && y < x) return 2;
        else if(y <= x && x <= z) return 1;
        else if(z <= x && x < y) return 1;
        else if(x < z && z < y) {
            if(z-x < y - z) {
                return 1;
            } else if(z-x == y -z) {
                return 0;
            }
            else {
                return 2;
            }
        }
        else if( y < z && z < x) {
            if(z - y < x - z) {
                return 2;
            } else if(z-y == x-z) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else return 0;
    }
};