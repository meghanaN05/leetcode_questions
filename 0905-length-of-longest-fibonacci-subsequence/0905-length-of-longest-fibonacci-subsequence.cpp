#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;  
        unordered_map<int, int> dp;  
        
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;  
        }

        int maxLength = 0;
        
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int prev = arr[j] - arr[i];  
                
                if (prev < arr[i] && index.find(prev) != index.end()) {
                    int k = index[prev]; 
                    int length = dp[k * n + i] + 1;  
                    
                    dp[i * n + j] = length;
                    maxLength = max(maxLength, length);
                } else {
                    dp[i * n + j] = 2;  
                }
            }
        }

        return maxLength > 2 ? maxLength : 0;   
    }
};
