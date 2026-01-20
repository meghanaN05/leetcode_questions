class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int>ans(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            ans.insert(stoi(s));
        }
        return ans.size();
    }
};