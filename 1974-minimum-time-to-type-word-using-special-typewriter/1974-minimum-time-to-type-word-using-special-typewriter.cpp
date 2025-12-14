class Solution {
public:
    int minTimeToType(string word) {
        int cnt=0;
        char p='a';
        for(int i=0;i<word.size();i++){
            int c=abs(p-word[i]);
            int ac=26-c;
            cnt+=min(c,ac)+1;
            p=word[i];

        }
        return cnt;
    }
};