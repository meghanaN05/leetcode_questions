class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<=nums[i] ){
                int prev=nums[i]+1;
                cnt+=abs(nums[i+1]-prev);
                nums[i+1]=prev;
            }
        }
        return cnt;
    }
};