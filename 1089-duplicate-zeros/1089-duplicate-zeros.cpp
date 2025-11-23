class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
      int l=0;
      int n=arr.size();
      vector<int>ans;
      for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            if(ans.size()<n)
            ans.push_back(arr[i]);
            if(ans.size()<n)
            ans.push_back(0);
        }
        else{
           if(ans.size()<n) ans.push_back(arr[i]);
        }
      }
      for(int i=0;i<n;i++){
        arr[i]=ans[i];
      }

    }
};