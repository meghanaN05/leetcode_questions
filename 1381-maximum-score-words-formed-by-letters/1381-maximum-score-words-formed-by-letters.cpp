class Solution {
public:
int n;
int maxi=0;
void backtrack(int i,vector<string>& words,vector<int>& score,int curr,vector<int>&freq){
      if (i == n) { 
            maxi = max(maxi, curr);
            return;
        }
    vector<int>tempfreq=freq;
    int j=0;
    int tempscore=0;
    while(j<words[i].size()){
        char ch=words[i][j];
        tempfreq[ch-'a']--;
        tempscore+=score[ch-'a'];
        if(tempfreq[ch-'a']<0) break;
        j++;
    }
    // taking the words[i]
    if(j==words[i].size()){
        backtrack(i+1,words,score,curr+tempscore,tempfreq);
    }
    backtrack(i+1,words,score,curr,freq);

}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        vector<int>freq(26,0);
        for(char c:letters){
            freq[c-'a']++;
        }
        backtrack(0,words,score,0,freq);
        return maxi;
    }
};