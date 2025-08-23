class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans1(n);
        for(int i=0;i<n;i++){
            ans1[i]=nums[i];
        }
        vector<int>ans2(n);
        for(int i=0;i<n;i++){
            ans2[i]=nums[n+i];
        }
        vector<int>ans(2*n);
        int j=0,w=0;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                ans[i]=ans1[j];
                j++;
            }
            else{
                ans[i]=ans2[w];
                w++;
            }
        }
        return ans;
    }
};