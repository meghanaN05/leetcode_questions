#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // Prefix sum array to store cumulative sums
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long long leftSum = prefSum[i];
            // Sum of right part (i+1 to n-1)
            long long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};