class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        long long score=0;
        int cnt=0;
        priority_queue<int>pq(nums.begin(),nums.end());
        while(cnt<k){
            int v=pq.top();
            pq.pop();
            score +=v;
            pq.push(v+1);
            cnt++;
        }
        return (int)score;

    }
};