class Solution {
public:
    vector<string>answer;
     void backtrack(int index,int n,int Open,string Current){
        if(index==n){
      if(Open==0) answer.push_back(Current);
      return;

        }
        backtrack(index+1,n,Open+1,Current+"(");
        if(Open) backtrack(index+1,n,Open-1,Current+")");
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0,2*n,0,"");
        return answer;
    }
};