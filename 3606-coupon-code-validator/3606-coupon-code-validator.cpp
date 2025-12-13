class Solution {
public:
    bool isValidCode(const string& code) {
    if (code.empty()) return false;
    for (char c : code) {
        if (!(isalnum(c) || c == '_')) return false;
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    unordered_map<string, int> categoryOrder = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };

    vector<pair<pair<int, string>, string>> valid;

    for (int i = 0; i < code.size(); ++i) {
        if (isActive[i] &&
            categoryOrder.find(businessLine[i]) != categoryOrder.end() &&
            isValidCode(code[i])) {
            valid.push_back({{categoryOrder[businessLine[i]], code[i]}, code[i]});
        }
    }

    sort(valid.begin(), valid.end());

    vector<string> result;
    for (auto& entry : valid) {
        result.push_back(entry.second);
    }

    return result;
    
    }
};