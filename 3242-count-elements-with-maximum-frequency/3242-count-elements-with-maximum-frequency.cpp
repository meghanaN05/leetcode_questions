class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int maxi=INT_MIN;
        for(auto it:freq){
            maxi=max(maxi,it.second);
        }

        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==maxi) cnt++;
        }
        return cnt;
    }
};