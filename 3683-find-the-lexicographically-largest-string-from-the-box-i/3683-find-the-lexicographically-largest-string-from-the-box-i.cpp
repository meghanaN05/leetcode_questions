class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.length();
        if(numFriends==1) return word;
        string result;
        int poss=n-(numFriends-1);
        for(int i=0;i<n;i++){
            int cantake=min(n-i,poss);
            result=max(result,word.substr(i,cantake));
        }
        return result;
    }
};