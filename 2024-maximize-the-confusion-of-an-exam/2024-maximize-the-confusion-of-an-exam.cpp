class Solution {
public:
    int maxConsecutiveAnswers(string t, int k) {
        int n=t.size();
        int res=0;
        int l=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(t[i]=='F') cnt++;
            while(cnt>k){
                if(t[l]=='F')
                cnt--;
                l++;
            }
            res=max(i-l+1,res);
        }
        cnt=0;
        l=0;
        for(int i=0;i<n;i++){
            if(t[i]=='T') cnt++;
            while(cnt>k){
                if(t[l]=='T')
                cnt--;
                l++;
            }
            res=max(i-l+1,res);
        }
        return res;

    }
};