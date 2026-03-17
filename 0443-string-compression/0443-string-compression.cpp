class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=0;
        string t="";
        char curr=chars[0];
       for(int i=0;i<chars.size()-1;i++){
        if(chars[i]==chars[i+1]){
           cnt++;
           curr=chars[i];
        }
        else{
            t+=chars[i];
            if(cnt>0)
            t+=to_string(cnt+1);
            cnt=0;
        }
       }
        t+=chars.back();
        if(cnt>0)
        t+=to_string(cnt+1);
       for(int i=0;i<min(t.size(),chars.size());i++){
        chars[i]=t[i];
       }
       return t.size();
          
    }
};