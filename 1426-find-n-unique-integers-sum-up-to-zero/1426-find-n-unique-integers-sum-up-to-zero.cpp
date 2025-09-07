class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
          vector<int>ans1;
        if(n%2==0){
            for(int i=-n/2;i<=n/2;i++){
                if(i==0) continue;
                ans.push_back(i);
            }
            return ans;
        }
        else{
            for(int i=-n/2;i<=n/2;i++){
                ans1.push_back(i);
            }
            return ans1;
        }
      
        return {-1};
    }
};