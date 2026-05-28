class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt=0;
        int zero=0;
        for(int i=0;i<nums.size();i++)
        if(nums[i]==0) zero++;
        for(int i=0;i<nums.size()-zero;i++){
            if(nums[i]==0){
                cnt++;
            }
        }
        return cnt;
    }
};