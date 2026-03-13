class Solution {
public:

    bool possible(long long mid, int mountainHeight, vector<int>& workerTimes){
        long long total = 0;
        for(int t : workerTimes){
            long long lo = 0, hi = 1e6;
            long long best = 0;
            while(lo <= hi){
                long long k = (lo + hi) / 2;
                long long time = (long long)t * (k * (k + 1) / 2);
                if(time <= mid){
                    best = k;
                    lo = k + 1;
                }
                else{
                    hi = k - 1;
                }
            }
            total += best;
            if(total >= mountainHeight) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long lo = 0;
        long long hi = 1e18;
        long long ans = hi;

        while(lo <= hi){
            long long mid = (lo + hi) / 2;
            if(possible(mid, mountainHeight, workerTimes)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};