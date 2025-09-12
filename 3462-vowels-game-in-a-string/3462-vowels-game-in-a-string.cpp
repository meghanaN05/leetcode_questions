class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
            || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }

    bool doesAliceWin(string s) {
        int v=0;
        for(auto c : s){
            if(isVowel(c)){
                v++;
            }
        }
        return v > 0;
    }
};
