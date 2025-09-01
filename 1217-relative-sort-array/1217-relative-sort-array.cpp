class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> leftover;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    ans.push_back(arr1[j]);
                    arr1[j] = -1;
                }
            }
        }
        for (int j = 0; j < arr1.size(); j++) {
            if (arr1[j] != -1) leftover.push_back(arr1[j]);
        }
        sort(leftover.begin(), leftover.end());
        ans.insert(ans.end(), leftover.begin(), leftover.end());

        return ans;
    }
};
