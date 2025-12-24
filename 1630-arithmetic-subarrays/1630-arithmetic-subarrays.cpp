class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> temp;
            for (int j = l[i]; j <= r[i]; j++) {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            bool ok = true;
            int d = temp[1] - temp[0];
            for (int k = 1; k < temp.size() - 1; k++) {
                if (temp[k + 1] - temp[k] != d) {
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
