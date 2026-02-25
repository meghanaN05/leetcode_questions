class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
            int c=__builtin_popcount(a);
            int d=__builtin_popcount(b);
            if(c==d) return a<b;
            return c<d;
        });
      return arr;
    }
};