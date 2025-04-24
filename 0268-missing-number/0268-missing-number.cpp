class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int total = 0, arrXor = 0;
for(int i = 0; i < nums.size(); i++) {
    total ^= i;
    arrXor ^= nums[i];
}
total ^= nums.size(); 
return total ^ arrXor;

    }
};