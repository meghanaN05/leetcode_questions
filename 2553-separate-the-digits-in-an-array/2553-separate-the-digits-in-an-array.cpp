class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            vector<int>ans;
            while(x>0){
                int digit=x%10;
                ans.push_back(digit);
                x=x/10;
            }
            reverse(ans.begin(),ans.end());
             res.insert(res.end(),ans.begin(),ans.end());
        }
        return res;
    }
};