class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int a=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            while(num>0){
                 a+=num%10;
                 num=num/10;
            }
        }
        return abs(sum-a);
    }
};