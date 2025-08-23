class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(int i=0;i<operations.size();i++){
            string s=operations[i];
            int n=s.size();
            if(s[0]=='+' || s[n-1]=='+') ans++;
              if(s[0]=='-' || s[n-1]=='-') ans--;
        }
        return ans;
    }
};