class Solution {
public:
int n;
string target;
string answer;
bool dfs(int pos, multiset<char>& ms, string &cur) {
    if (pos == n) {
        return false;
    }

    for (char ch = target[pos]; ch <= 'z'; ++ch) {
        auto it = ms.find(ch);
        if (it == ms.end()) continue;

       
        ms.erase(it);
        cur.push_back(ch);

        if (ch > target[pos]) {
           
            string tmp = cur;
            for (char c : ms) tmp.push_back(c);
            answer = tmp;
            return true;
        } else {
          
            if (dfs(pos + 1, ms, cur)) return true;
        }

        // backtrack
        cur.pop_back();
        ms.insert(ch);
    }
    return false;
}
    string lexGreaterPermutation(string s, string tgt) {
           n = s.size();
    target = tgt;
    answer = "";

    multiset<char> ms(s.begin(), s.end());
    string cur = "";
    if (dfs(0, ms, cur)) return answer;
    return "";

    }
};