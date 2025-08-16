
class Solution {
public:
    multiset<long long> lo, hi; // lo = max-half, hi = min-half
    int k;

    void rebalance() {
        // ensure |lo| >= |hi| and diff ≤ 1
        while (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        while (hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }

    double getMedian() {
        if (k % 2 == 1) return *lo.rbegin();
        return ((double)*lo.rbegin() + *hi.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        this->k = k;
        vector<double> result;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Insert nums[i]
            if (lo.empty() || nums[i] <= *lo.rbegin())
                lo.insert(nums[i]);
            else
                hi.insert(nums[i]);

            rebalance();

            // 2. Remove outgoing element
            if (i >= k) {
                int out = nums[i - k];
                if (lo.find(out) != lo.end())
                    lo.erase(lo.find(out));
                else
                    hi.erase(hi.find(out));
                rebalance();
            }

            // 3. Add median to result
            if (i >= k - 1) result.push_back(getMedian());
        }

        return result;
    }
};
