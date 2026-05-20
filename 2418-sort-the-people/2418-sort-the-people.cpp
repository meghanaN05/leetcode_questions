class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>s;
        for(int i=0;i<names.size();i++){
            s.push_back({heights[i],names[i]});
        }
        sort(s.rbegin(),s.rend());
       vector<string>ans;
       for(auto it:s){
        ans.push_back(it.second);
       }
       return ans;
    }
};