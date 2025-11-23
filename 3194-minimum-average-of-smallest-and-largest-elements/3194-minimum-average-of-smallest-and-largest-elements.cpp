class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        vector<double>average;
        int cnt=0;
        while(cnt<n/2){
            cnt++;
            sort(nums.begin(),nums.end());
              double first=nums[0];
              double end=nums[nums.size()-1];
              nums.erase(nums.begin());
              nums.pop_back();
              average.push_back((first+end)/2.0);
        }
        sort(average.begin(),average.end());
        return average[0];
    }
};