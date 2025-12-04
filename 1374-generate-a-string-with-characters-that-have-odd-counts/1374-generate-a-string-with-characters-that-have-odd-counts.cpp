class Solution {
public:
    string generateTheString(int n) {
        int real=n;
        if(n%2==0) n=n-1; 
        string s="";
        for(int i=0;i<n;i++){
            s+='a';
        }
        if(real%2==0){
           s+='b';
           return s;
        } 
         return s;
        
    }
};