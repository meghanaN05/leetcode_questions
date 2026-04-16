class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>si;
        unordered_map<int,int>ti;
        for(int i=0;i<s.size();i++){
            si[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            ti[t[i]-'a']++;
        }
        int cnt=0;
       for(int i = 0; i < 26; i++){
            int x = si[i];
            int y = ti[i];
            if(y < x) cnt += (x - y);
        }
        return cnt;
    }
};