class Solution {
public:
vector<int>ans;
vector<int>backtrack(int start,int end,string &exp){
    int length=end-start+1;
    if(length<=2) return{stoi(exp.substr(start,length))};
     vector<int>possibleval;
     for(int i=start;i<=end;i++){
        if(exp[i]=='-'|| exp[i]=='*'|| exp[i]=='+'){
            vector<int>leftvalues=backtrack(start,i-1,exp);
            vector<int>rightvalues=backtrack(i+1,end,exp);
            for(auto &x:leftvalues){
                for(auto &y:rightvalues){
                    if(exp[i]=='-')possibleval.push_back(x-y);
                    if(exp[i]=='+')possibleval.push_back(x+y);
                    if(exp[i]=='*')possibleval.push_back(x*y);
                }
            }
        }
     }
     return possibleval;
}
    vector<int> diffWaysToCompute(string expression) {
     return   backtrack(0,expression.size()-1,expression) ;
    }
};