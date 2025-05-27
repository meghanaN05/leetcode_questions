class Solution {
public:
 vector<vector<int>>final;
   void helper(vector<int>& ans,vector<int>& nums,int index,int n){
    if(index>=n){
        final.push_back(ans);
        return;
    }
    ans.push_back(nums[index]);
    helper(ans,nums,index+1,n);
    ans.pop_back();
     helper(ans,nums,index+1,n);

   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        helper(ans,nums,0,nums.size());
        return final;
    }
};