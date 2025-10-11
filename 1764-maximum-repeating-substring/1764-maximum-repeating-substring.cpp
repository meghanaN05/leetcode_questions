class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int cnt=0;
        string t=word;
        while(sequence.find(t)!=string::npos)
        {
            cnt++;
            t+=word;
        }
        return cnt;
    }
};