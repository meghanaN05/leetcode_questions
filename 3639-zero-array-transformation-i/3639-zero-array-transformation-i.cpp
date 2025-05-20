class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans(nums.size()+1,0);
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            ans[l]+=1;
            ans[r+1]-=1;
        }
        vector<int>op;
        int cu_op=0;
        for(int delta:ans){
            cu_op+=delta;
            op.push_back(cu_op);
        }
         for (int i = 0; i < nums.size(); ++i) {
            if (op[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};