class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long count=0;
        long long zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                zero+=count;
            }
            else{
                count=0;
            }
        }

       return zero;
    }
};