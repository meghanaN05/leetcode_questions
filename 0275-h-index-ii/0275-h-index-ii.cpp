class Solution {
public:
bool can(int x,vector<int>&citations){
    int ans=0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=x) ans++;
    }
    return ans>=x;
}
    int hIndex(vector<int>& citations) {
        int l=0;
        int h=citations.size();
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(can(mid,citations)){
                 ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;

    }
};