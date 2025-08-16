
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> st; 
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);

           
            if (i >= k) {
                st.erase(st.find(nums[i - k]));
            }

            if (i >= k - 1) {
                ans.push_back(*st.rbegin()); 
            }
        }
        return ans;
    }
};
