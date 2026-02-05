class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<nums.size();i++){
          res.push_back(nums[((i + nums[i]) % n + n) % n]);
        }
        return res;
    }
};