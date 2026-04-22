class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> a;
        for(int i = 0; i < queries.size(); i++) {
            string ans = queries[i];
            for(int j = 0; j < dictionary.size(); j++) {
                string word = dictionary[j];
                int cnt = 0;
                for(int k = 0; k < word.size(); k++) {
                    if(word[k] != ans[k]) cnt++;
                }
                if(cnt <= 2) {
                    a.push_back(ans);
                    break;  
                }
            }
        }
        return a;
    }
};