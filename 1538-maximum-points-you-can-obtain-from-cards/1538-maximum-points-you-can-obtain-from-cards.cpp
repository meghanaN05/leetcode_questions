class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;

        
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int maxSum = sum;
       
        for (int i = 1; i <= k; i++) {
            sum -= cardPoints[k - i];        
            sum += cardPoints[n - i];        
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
