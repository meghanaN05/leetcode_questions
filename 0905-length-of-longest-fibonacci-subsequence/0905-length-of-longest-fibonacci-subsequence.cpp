#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> set(arr.begin(), arr.end()); 
        int maxLength = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j], len = 2;  

                
                while (set.find(a + b) != set.end()) {
                    int next = a + b;
                    a = b;
                    b = next;
                    len++;
                    maxLength = max(maxLength, len);
                }
            }
        }

        return maxLength > 2 ? maxLength : 0; 
    }
};
