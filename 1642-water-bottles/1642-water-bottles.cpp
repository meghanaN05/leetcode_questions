class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n=numBottles;
        int k=numExchange;
         return n+(n-1)/(k-1);
    }
};