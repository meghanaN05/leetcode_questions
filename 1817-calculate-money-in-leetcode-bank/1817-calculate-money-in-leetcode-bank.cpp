class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7; 
        int days = n % 7;
       return (weeks* (49 + 7 * weeks) + days * (2 * weeks + days+ 1)) / 2;
    }
};
