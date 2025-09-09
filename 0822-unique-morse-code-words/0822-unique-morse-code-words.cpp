class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>s={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
     set<string>st;
        for(int i=0;i<words.size();i++){
            string w=words[i];
            string si="";
            for(auto ch:w){
              si+=s[ch-'a'];
            }
           st.insert(si);
        }
        return st.size();
    }
};