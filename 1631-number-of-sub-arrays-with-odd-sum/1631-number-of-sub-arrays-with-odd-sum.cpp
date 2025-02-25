class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
          long long mod=1000000007;
          long long oddcount=0,prefixsum=0;
          for(int i=0;i<arr.size();i++){
            prefixsum +=arr[i];
            oddcount +=prefixsum%2;
          }
          oddcount+=(arr.size()-oddcount)*oddcount;
          return (oddcount%mod);

    }
};