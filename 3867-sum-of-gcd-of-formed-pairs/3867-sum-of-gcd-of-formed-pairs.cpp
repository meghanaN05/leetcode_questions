class Solution {
public:
int maxi=0;
    long long gcdSum(vector<int>& nums) {
        vector<int>prefix(nums.size());
        for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
         prefix[i]=__gcd(nums[i],maxi);
        }
        sort(prefix.begin(),prefix.end());
        long long sum=0;
        for(int i=0;i<prefix.size()/2;i++){
          sum+=__gcd(prefix[i],prefix[prefix.size()-i-1]);
        }
        return sum;
    }
    
};