class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        int i = 0;
        for (auto it : mp) {
            if (it.second >= 2) {
                nums[i] = it.first;
                i++;
                nums[i] = it.first;
                i++;  
            } else {
                nums[i] = it.first;
                i++;
            }
        }
        return i;  
    }
};
