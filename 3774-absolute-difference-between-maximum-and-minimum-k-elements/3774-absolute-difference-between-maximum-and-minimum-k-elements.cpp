class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum1=0;
        for(int i=0;i<k;i++){
            sum1+=nums[i];
        }
         int sum2 = 0;
        int n = nums.size();
        for (int i = n - k; i < n; ++i) {
            sum2+= nums[i];
        }
        return abs(sum1-sum2);
    }
};