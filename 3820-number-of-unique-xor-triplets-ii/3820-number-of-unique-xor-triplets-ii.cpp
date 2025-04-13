class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool>po(3001,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               po[nums[i]^nums[j]]=true;
            }
        }
        vector<bool>newpo(3001,false);
        for(int i=0;i<=3000;i++){
            for(int j=0;j<n;j++){
                if(((i^nums[j])<=3000)&& po[i^nums[j]]){
                    newpo[i]=true;
                    break;
                }
            }
        }
        return count(newpo.begin(),newpo.end(),true);

    }
};