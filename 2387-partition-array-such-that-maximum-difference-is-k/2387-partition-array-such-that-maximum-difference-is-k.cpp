class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int count=1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]-mini>k){
                count++;
                mini=nums[i];
            }
        }
        return count;
    }
};