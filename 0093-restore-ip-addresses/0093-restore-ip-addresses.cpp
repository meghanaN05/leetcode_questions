class Solution {
public:
   vector<string>ip;
   bool isokay(string s){
    int number =stoi(s);
    string actual=to_string(number);
    return (s==actual && number<=255);
   }
   void backtrack(int index,int sections,string &s,string current){
    if(index==s.size() || sections==4){
        current.pop_back();
    
    if(index==s.size() && sections==4)
        ip.push_back(current);
        return;}
    for(int len=1;len<=3;len++){
        if(len+index<=s.size() && isokay(s.substr(index,len))){
            backtrack(index+len,sections+1,s,current+s.substr(index,len)+".");
        }
    }

   }
    vector<string> restoreIpAddresses(string s) {
         backtrack(0,0,s,"");
         return ip;
    }
};