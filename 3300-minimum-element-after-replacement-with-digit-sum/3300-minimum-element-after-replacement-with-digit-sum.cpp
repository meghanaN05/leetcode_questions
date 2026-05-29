class Solution {
public:
int digits(int x){
    int sum=0;
    while(x>0){
        sum+=x%10;
        x=x/10;
    }
    return sum;
}
    int minElement(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int sum=digits(nums[i]);
            ans.push_back(sum);
            
        }
        int a= *min_element(ans.begin(),ans.end());
        return a;
    }
};