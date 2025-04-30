class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int c = 0;  // current load
            int r = 1;  // day count

            for (int it : weights) {
                if (c + it > mid) {
                    r++;
                    c = 0;
                }
                c += it;
            }

            if (r <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
