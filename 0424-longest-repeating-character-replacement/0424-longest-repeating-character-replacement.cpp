class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int maxi=0;
        vector<int>freq(26,0);
        int res=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            maxi=max(maxi,freq[s[i]-'A']);
            
            while(i-l+1-maxi>k){
               freq[s[l]-'A']--;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};