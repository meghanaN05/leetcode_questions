class Solution {
public:
int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    int atMostK(vector<int>& nums, int k) {
        int l=0;
        int ans=0;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            while(freq.size()>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0)
                freq.erase(nums[l]);
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};