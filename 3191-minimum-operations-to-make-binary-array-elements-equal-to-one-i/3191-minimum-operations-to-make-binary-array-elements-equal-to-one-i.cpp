class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op=0;
        int j=0;
        int i=0;
           while(i<nums.size()-2){
            int e1=nums[i];
            int e2=nums[i+1];
            int e3=nums[i+2];
            if(e1==0){
                op++;
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
            i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) return -1;
        }
        return op;
    }
};