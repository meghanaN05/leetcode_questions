class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int k=words.size();
        string res="";
        for(int i=0;i<words.size();i++){
            res+=words[i];
            if(res==s) return true;
        }
        return false;
    }
};