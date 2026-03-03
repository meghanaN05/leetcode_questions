class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi=0;
        unordered_map<char,int>mp;
        int l=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};