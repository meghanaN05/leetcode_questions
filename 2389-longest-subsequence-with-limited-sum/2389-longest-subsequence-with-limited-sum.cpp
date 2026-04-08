class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m=queries.size();
        vector<int>ans(m);
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            int x=queries[i];
            int cnt=0;
            int sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=nums[j];
                if(sum<=x){
                 cnt++;
                }
                else{
                    break;
                }
                 ans[i] = cnt;
                
            }
        }
        return ans;
    }
};