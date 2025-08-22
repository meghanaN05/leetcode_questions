class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int>even;
        vector<int>odd;
        vector<int>ans(n);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        int j=0,w=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans[i]=even[j];
                j=j+1;
            }
            else{
                ans[i]=odd[w];
                w=w+1;
            }
           
        }
       return ans;
    }
};