class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        pre[i]=pre[i-1]+nums[i];
        vector<int>post(n);
        post[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
         post[i]=post[i+1]+nums[i];
         
        }
        for(int i=0;i<n;i++){
            if(pre[i]==post[i]) return i;
         }
        return -1;
    }
};