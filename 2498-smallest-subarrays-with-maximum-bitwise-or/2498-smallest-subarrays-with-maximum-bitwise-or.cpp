class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        vector<int>set(32,-1);
        for(int i=n-1;i>=0;i--){
            int endindex=i;
            for(int j=0;j<32;j++){
                if((nums[i]&(1<<j))==0){
                    if(set[j]!=-1){
                        endindex=max(endindex,set[j]);
                    }
                }
                else{
                    set[j]=i;
                }
            }
            result[i]=endindex-i+1;
        }
        return result;
    }
};