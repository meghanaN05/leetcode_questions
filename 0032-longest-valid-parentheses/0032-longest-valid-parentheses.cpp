class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int>idx;
        stack<int>st;
        idx.push(-1);
        int ans=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                st.push(s[i]);
                idx.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                    idx.pop();
                    ans=max(ans,i-idx.top());
                }
                else{
                    idx.push(i);
                }
            }
            i++;
        }
        return ans;
    }
};