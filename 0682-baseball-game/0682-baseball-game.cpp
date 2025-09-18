class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                if (!ans.empty()) ans.pop_back();
            } 
            else if (operations[i] == "D") {
                ans.push_back(ans.back() * 2);
            } 
            else if (operations[i] == "+") {
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            } 
            else { 
                int val = stoi(operations[i]);
                ans.push_back(val);
            }
        }
        int total = 0;
        for (int x : ans) total += x;
        return total;
    }
};
