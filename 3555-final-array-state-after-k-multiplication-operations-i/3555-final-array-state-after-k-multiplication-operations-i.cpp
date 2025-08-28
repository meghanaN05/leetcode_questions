class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        int ans=0;
        while(ans<k){
            int mini=*min_element(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                if(nums[i]==mini){
                    nums[i]=nums[i]*multiplier;
                    ans++;
                    break;
                }
            }
        }
        return nums;
    }
};