class Solution {
public:

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, vector<int>> mp;

  
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    sort(nums.begin(), nums.end());

    int i = 0;
    int j = nums.size() - 1;

    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum < target)
            i++;
        else if (sum > target)
            j--;
        else {
           
            if(nums[i]!=nums[j])
            return { mp[nums[i]][0], mp[nums[j]][0] };
            else 
           return { mp[nums[i]][0], mp[nums[i]][1] };
        }
    }

    return {-1, -1};
}

};