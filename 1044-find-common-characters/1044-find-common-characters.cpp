class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> init(26);
        for (char c : words[0]) init[c - 'a']++;

        vector<int> temp(26);
        for (int i = 1; i < words.size(); i++) {
            for (char c : words[i]) temp[c - 'a']++;

            for (int i = 0; i < 26; i++) {
                init[i] = min(init[i], temp[i]);
            }
            fill(temp.begin(), temp.end(), 0);
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < init[i]; j++) {
                res.push_back(string(1,'a' + i));
            }
        }
        return res;
    }
};