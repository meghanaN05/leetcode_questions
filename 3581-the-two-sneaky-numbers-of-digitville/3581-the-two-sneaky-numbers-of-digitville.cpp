class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        set<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                ans.insert(nums[i]);
            }
        }
         vector<int> v(ans.begin(),ans.end());
        return v;

    }
};