class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        int index = 1;
        for (int i = 0; i <= sentence.size(); i++) {
        if (i == sentence.size() || sentence[i] == ' ') {
        if (word.find(searchWord) == 0) {
            return index;
                }
            word.clear();
                index++;
            } else {
                word += sentence[i];
            }
        }
        return -1;
    }
};
