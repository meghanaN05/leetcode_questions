class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(nums[i]);
            }
            else{
                a.push_back(nums[i]);
            }
        }
         ans.insert(ans.end(),a.begin(),a.end());
         return ans;
    }
};