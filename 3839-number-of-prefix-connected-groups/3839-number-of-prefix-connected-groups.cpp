class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        int ans = 0;
        string last = "";
        for(int i = 0; i < words.size() - 1; i++){
            string s = words[i];
            string t = words[i + 1];
            if(s.size() < k || t.size() < k) continue;
            int cnt = 0;
            for(int j = 0; j < k; j++){
                if(s[j] == t[j]){
                    cnt++;
                }
                else{
                    break;   
                }
            }
            if(cnt == k){
                string pref = s.substr(0, k);
                if(pref != last){   
                    ans++;
                    last = pref;
                }
            }
        }
        return ans;
    }
};
