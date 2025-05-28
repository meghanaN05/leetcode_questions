class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> uniqueNumbers;  // To store distinct 3-digit even numbers

        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue;  

                    int a = digits[i], b = digits[j], c = digits[k];
                    if (a == 0) continue;   
                    if (c % 2 != 0) continue; 

                    int number = a * 100 + b * 10 + c;
                    uniqueNumbers.insert(number); 
                }
            }
        }

        return uniqueNumbers.size();
    }
};
