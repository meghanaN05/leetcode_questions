class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>mp;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            while(s.size() && nums2[i]>=s.top()){
                s.pop();
            }
            if(s.size()){
                mp[nums2[i]]=s.top();
                s.push(nums2[i]);
            }
            else{
                mp[nums2[i]]=-1;
                s.push(nums2[i]);
            }
        }
        vector<int>ans;
        int m=nums1.size();
        for(int i=0;i<m;i++){
           ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};