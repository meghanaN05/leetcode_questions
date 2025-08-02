class Solution {
public:
bool possible(vector<int>& nums,int mid){
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid)
        cnt++;
    }
    return cnt>mid;
}
    int findDuplicate(vector<int>& nums) {
            long long low = 1, high = nums.size()-1, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (possible(nums,mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};