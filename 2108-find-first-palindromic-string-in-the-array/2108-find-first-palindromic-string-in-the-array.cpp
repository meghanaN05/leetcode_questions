class Solution {
public:
    bool ispalindrome(string word){
        string s=word;
        reverse(s.begin(),s.end());
        return s==word;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string word=words[i];
        if(ispalindrome(word))
            return word;
        }
        return "";
    }
};