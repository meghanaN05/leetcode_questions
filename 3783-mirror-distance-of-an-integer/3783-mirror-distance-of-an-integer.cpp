class Solution {
public:
  int rev(int n){
    string s=to_string(n);
    reverse(s.begin(),s.end());
    return stoi(s);
  }
    int mirrorDistance(int n) {
        int nn=rev(n);
      return   abs(n-nn);
    }
};