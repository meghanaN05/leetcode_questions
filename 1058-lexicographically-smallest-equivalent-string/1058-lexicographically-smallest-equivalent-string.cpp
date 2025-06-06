class Solution {
public:
char DFSarray(unordered_map<int,vector<char>>&a,char &ch,vector<int>&visited){
    visited[ch-'a']=1;
    char minchar=ch;
    for(char &v:a[ch]){
        if(visited[v-'a']==0){
            minchar=min(minchar,DFSarray(a,v,visited));
        }
    }
    return minchar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        int m=baseStr.size();
        unordered_map<int,vector<char>>a;
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            a[u].push_back(v);
             a[v].push_back(u);
        }
        string result;
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            vector<int>visited(26,0);
            char minchar=DFSarray(a,ch,visited);
            result.push_back(minchar);
        }
        return result;
    }
};