class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int op=0;
        priority_queue<int>pq(gifts.begin(),gifts.end());
        while(op<k){
           op++;
           int t=pq.top();
           pq.pop();
           pq.push(floor(sqrt(t)));

        }
         long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};