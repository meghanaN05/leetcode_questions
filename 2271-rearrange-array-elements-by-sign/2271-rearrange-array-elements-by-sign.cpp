class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int num : nums) {
            if (num < 0) {
                neg.push_back(num);
            } else {
                pos.push_back(num);
            }
        }

        vector<int> ans;
        int i = 0, j = 0;
        for (int k = 0; k < nums.size(); ++k) {
            if (k % 2 == 0) {
                ans.push_back(pos[i++]);
            } else {
                ans.push_back(neg[j++]);
            }
        }
        return ans;
    }
};
