class Solution {
public:
      vector<vector<int>>ans;
      vector<int>current;
      void solve(int i,vector<int>& nums){
        if(i==nums.size()){
         ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        solve(i+1,nums);
        current.pop_back();
        solve(i+1,nums);

      }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
      return ans;
    }
};