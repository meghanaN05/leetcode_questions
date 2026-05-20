class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        unordered_map<char,int>mp;
        for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
        }
        for(auto s:words){
            string r=s;
            bool ok=true;
            for(int i=0;i<r.size();i++){
                if(mp[r[i]]==0) ok=false;;
            }
            if(ok) cnt++;
        }
        return cnt;
    }
};