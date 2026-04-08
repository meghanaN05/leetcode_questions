class Solution {
public:
    int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int p = queries[i][3];
            while(l <= r){
                nums[l] = 1LL * nums[l] * p % MOD; 
                l += k;
            }
        }
        int xori = 0;
        for(int i = 0; i < nums.size(); i++){
            xori ^= nums[i];
        }
        return xori;
    }
};