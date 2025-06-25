class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, current = 1;
        while (k > 0) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                k--;
                if (k == 0) return current;
            }
            current++;
        }
        return current;
    }
};
