class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int xor1=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
          if(nums[i]==nums[i+1]){
            xor1=xor1^nums[i];
            i++;
          }
        }
        return xor1;
    }
};