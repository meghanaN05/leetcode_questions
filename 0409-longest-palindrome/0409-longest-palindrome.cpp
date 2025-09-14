class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>freq_a(26,0);
          vector<int>freq_A(26,0);
          for(int i=0;i<s.size();i++){
            if(islower(s[i]))
            freq_a[s[i]-'a']++;
            else
            freq_A[s[i]-'A']++;
          }
          int cnt=0;
          int oddcnt=0;
          for(int i=0;i<26;i++){
            if(freq_a[i]%2==0){
                cnt+=freq_a[i];
            }
            if(freq_A[i]%2==0){
                cnt+=freq_A[i];
            }
            if(freq_a[i]%2==1){
                cnt+=freq_a[i]-1;
                oddcnt++;
            }
            if(freq_A[i]%2==1){
                cnt+=freq_A[i]-1;
                oddcnt++;
            }
          }
          if(oddcnt>0)
          cnt++;

          return cnt;
    }
};