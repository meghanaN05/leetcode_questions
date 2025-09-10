class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sad;

        for (auto &f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            unordered_set<int> langSet(languages[u].begin(), languages[u].end());
            bool canTalk = false;
            for (int lang : languages[v]) {
                if (langSet.count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                sad.insert(u);
                sad.insert(v);
            }
        }

        vector<int> language(n + 1, 0);
        int mostKnownLang = 0;
        for (int user : sad) {
            for (int lang : languages[user]) {
                language[lang]++;
                mostKnownLang = max(mostKnownLang, language[lang]);
            }
        }

        return sad.size() - mostKnownLang;
    }
};
