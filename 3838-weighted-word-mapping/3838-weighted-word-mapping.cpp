class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="abcdefghijklmnopqrstuvwxyz";
        reverse(s.begin(),s.end());
        string res="";
        for(int j=0;j<words.size();j++){
            string si=words[j];
            int sum=0;
            for(int i=0;i<si.size();i++){
                sum+=weights[si[i]-'a'];
            }
            int ans=sum%26;
            res+=s[ans];
        }
        return res;
    }
};