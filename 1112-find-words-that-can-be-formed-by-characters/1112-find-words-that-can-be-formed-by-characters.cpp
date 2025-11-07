class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        for (char c : chars) {
            mp[c]++;
        }
        int sum = 0;
        for (string word : words) {
            unordered_map<char, int> temp = mp;
            bool good = true;
            for (char c : word) {
                if (temp[c] > 0) {
                    temp[c]--; 
                } else {
                    good = false;
                    break;
                }
            }
            if (good) sum += word.size();  
        }
        return sum;
    }
};
