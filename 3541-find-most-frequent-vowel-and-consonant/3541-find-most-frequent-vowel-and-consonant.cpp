class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int max_v=0;
        int max_c=0;
        for(auto it:mp){
            if(it.first=='a' ||it.first=='e'|| it.first=='i'|| it.first=='o'|| it.first=='u'){
                max_v=max(max_v,it.second);
            }
            else{
                max_c=max(max_c,it.second);
            }
        }
        return max_v+max_c;
    }
};