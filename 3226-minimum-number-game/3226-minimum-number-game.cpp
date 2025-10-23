class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),nums.end());
        vector<int>ans;
        while(!pq.empty()){
           int x=pq.top();
           pq.pop();
           int y=pq.top();
           pq.pop();
           ans.push_back(y);
           ans.push_back(x);
        }
        return ans;
    }
};