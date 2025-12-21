class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n=cost.size();
        vector<long long>arr(26,0);
        long long t=0;
        long long maxi=0;
        for(int i=0;i<n;i++){
            t+=cost[i];
            arr[s[i]-'a']+=cost[i];
            if(arr[s[i]-'a']>maxi){
                maxi=arr[s[i]-'a'];
            }
        }
        return t-maxi;
    }
};