class Solution {
public:
    bool checker(int mid, vector<int>& piles, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;  
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()), ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (checker(mid, piles, h)) {
                ans = mid;
                r = mid - 1;  
            } else {
                l = mid + 1;  
            }
        }
        return ans;
    }
};
