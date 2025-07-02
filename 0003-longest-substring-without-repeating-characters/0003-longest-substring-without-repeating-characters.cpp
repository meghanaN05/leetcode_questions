class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
       int l=0;
       int maxi=1;
       unordered_map<int,int>freq;
       for(int i=0;i<s.size();i++){
         freq[s[i]-'a']++;
         while(freq[s[i]-'a']>1){
            freq[s[l]-'a']--;
            if(freq[s[l]-'a']==0)
            freq.erase(s[l]-'a');
            l++;
         }
         maxi=max(maxi,i-l+1);
       }
       return maxi;
    }
};