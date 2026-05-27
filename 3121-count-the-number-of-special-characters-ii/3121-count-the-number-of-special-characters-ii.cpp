class Solution{
public:
int numberOfSpecialChars(string word){
vector<int>lower(26,-1),upper(26,1e9);
for(int i=0;i<word.size();i++){
char ch=word[i];
if(ch>='a'&&ch<='z') lower[ch-'a']=i;
else upper[ch-'A']=min(upper[ch-'A'],i);
}
int cnt=0;
for(int i=0;i<26;i++){
if(lower[i]!=-1&&upper[i]!=1e9&&lower[i]<upper[i]) cnt++;
}
return cnt;
}
};