class Solution {
public:
    int findGCD(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ans=__gcd(nums[0],nums[nums.size()-1]);
       return ans;
    }
};