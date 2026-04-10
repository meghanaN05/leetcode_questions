class Solution {
public:
    string reverseStr(string s, int k) {
        string res = "";
        int cnt = 0;
        string t = "";
        for(int i = 0; i < s.size(); i++){
            cnt++;
            t += s[i];
            if(cnt == k){
                reverse(t.begin(), t.end());
                res += t;
                t = "";
            }
            else if(cnt == 2*k){
                res += t;
                t = "";
                cnt = 0;
            }
        }
        if(!t.empty()){
            if(cnt < k){
                reverse(t.begin(), t.end());
            }
            res += t;
        }

        return res;
    }
};