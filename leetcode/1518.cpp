class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0;
        int empty = 0;
        while (numBottles) {
            drink += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }
        return drink;
    }
};