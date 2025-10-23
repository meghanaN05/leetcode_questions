class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long time = customers[0][0] + customers[0][1];
        long long waiting_time = time - customers[0][0];
        
        for (int i = 1; i < n; i++) {
            if (time < customers[i][0]) time = customers[i][0]; 
            time += customers[i][1];
            waiting_time += time - customers[i][0];
        }
        
        double average = (double)waiting_time / n;
        return average;
    }
};
