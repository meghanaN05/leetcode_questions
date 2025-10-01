class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int i=0;
        int j=0;
        bool ok=true;
        while(i<word1.size() && j<word2.size()){
          if(ok){
            s+=word1[i];
            i++;
          }
          if(!ok){
            s+=word2[j];
            j++;
          }
          ok=!ok;
          
        }
         while (i < word1.size()) {
            s += word1[i++];
        }
        while (j < word2.size()) {
            s += word2[j++];
        }

        return s;

    }
};