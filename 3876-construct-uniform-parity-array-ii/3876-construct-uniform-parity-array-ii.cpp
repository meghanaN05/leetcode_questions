class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = INT_MAX;
        int n = nums.size();
          int even=0; int odd=0;
        for(auto x:nums){
            if(x%2==0) even++;
            else odd++;
        }
        if(even == n || odd == n) return true; 
        
        for(int x : nums) {
            if(x % 2 == 1) {
              mn=min(mn,x);
            }
            }
           for(auto x:nums){
            if(x%2==0 && x-mn<1) return false;
        }

        return true;
    }
};