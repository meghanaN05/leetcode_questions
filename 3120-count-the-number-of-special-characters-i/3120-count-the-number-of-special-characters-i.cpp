class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>l;
        set<char>u;
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z') l.insert(word[i]);
            if(word[i]>='A' && word[i]<='Z') u.insert(word[i]);
        }
        int cnt=0;
        for(auto it:l){
          if(u.find(toupper(it))!=u.end()) cnt++;
        }
        return cnt;
    }
};