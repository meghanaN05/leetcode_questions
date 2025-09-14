class Solution {
public:
unordered_set<string>exact;
unordered_map<string,string>alcase;
unordered_map<string,string>vowelcase;
    string Lower(const string& s) {
        string res = s;
        for (char& c : res) {
            c = tolower(c);
        }
        return res;
    }

    string masked( const string& s){
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }
     string checkForMatch(const string& query) {
    if (exact.count(query)) 
        return query;

    string result = Lower(query);
    if (alcase.find(result) != alcase.end())
        return alcase[result];

    string ans = masked(result);
    if (vowelcase.find(ans) != vowelcase.end())
        return vowelcase[ans];

    return "";
}

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exact.clear();
        alcase.clear();
        vowelcase.clear();
        for(auto s:wordlist){
            exact.insert(s);
            string result=Lower(s);
            if(alcase.find(result)==alcase.end())
            alcase[result]=s;
            string result2=masked(result);
            if(vowelcase.find(result2)==vowelcase.end())
            vowelcase[result2]=s;

}
             vector<string> result;
        for (string query : queries) {
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};