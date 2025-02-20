class Solution {
public:
    bool isValid(string s) {
      stack<char>st;
      for(int i=0;i<s.size();i++){
        if(s[i]=='('|| s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            char c=s[i];
            if(c==')'){
                if(st.top()=='('){
                    st.pop();
                }
                else return false;
            }
            if(c=='}'){
                if(st.top()=='{'){
                    st.pop();
                }
                else return false;
            }
            if(c==']'){
                if(st.top()=='['){
                    st.pop();
                }
                else return false;
            }
        }
      } 
      if(st.empty())
      return true;
      else return false;
    }
};