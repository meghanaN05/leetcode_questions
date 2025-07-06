class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>freq;
        int l=0;
        int n=s.size();
        int count=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
          while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
            count+=n-i;
            freq[s[l]-'a']--;
            l++;
          }
            
        }
        return count;
    }
};