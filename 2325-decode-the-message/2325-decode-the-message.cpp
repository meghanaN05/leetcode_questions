class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<int,int> mp;
        string s="";
        for(int i=0;i<key.size();i++){
            if(key[i]==' ') continue;
            if(mp[key[i]-'a']==0){
                s+=key[i];
            }
            mp[key[i]-'a']++;
        }
        unordered_map<char,char> mp2;
        for(int i=0;i<s.size();i++){
            mp2[s[i]] = 'a' + i;
        }

        string ans="";
        for(int i=0;i<message.size();i++){
            if(message[i]!=' ')
                ans += mp2[message[i]];  
            else 
                ans += " ";
        }
        
        return ans;
    }
};