class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(auto &word:words){
            string rw=word;
            swap(rw[0],rw[1]);
            if(mp[rw]>0){
                ans+=4;
                mp[rw]--;
            }
            else{
                mp[word]++;
            }
        }
        for(auto &it:mp){
            string word=it.first;
            int count=it.second;
            if(word[0]==word[1]&& count>0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};