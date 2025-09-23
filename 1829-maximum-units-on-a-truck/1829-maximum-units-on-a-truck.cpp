class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto &b){
          return a[1]>b[1];
        });
        int ans=0;
        for(auto it:boxTypes){
            int a=min(it[0],truckSize);
            ans+=a*it[1];
            truckSize-=a;
              if (truckSize == 0) break; 
        }
             return ans;
    }
};