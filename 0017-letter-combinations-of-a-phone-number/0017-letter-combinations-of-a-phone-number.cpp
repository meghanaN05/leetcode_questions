class Solution {
public:
vector<string>number{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ans;
void backtrack(int index,string &digits,string current){
    if(index==digits.size()){
        ans.push_back(current);
        return;
    }
    for(auto &letter:number[digits[index]-'0']){
        backtrack(index+1,digits,current+letter);
    }
}
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0){
            return {};
        }
        backtrack(0,digits,"");
        return ans;
    }
};