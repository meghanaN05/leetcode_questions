class Solution {
public:
    int win(int n, int k) {
        if (n == 1) return 0;              
        return (win(n - 1, k) + k) % n;    
    }

    int findTheWinner(int n, int k) {
        return win(n, k) + 1;   
    }
};
