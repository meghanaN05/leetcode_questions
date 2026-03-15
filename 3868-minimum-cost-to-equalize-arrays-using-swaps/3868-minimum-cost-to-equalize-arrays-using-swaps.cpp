class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> f1,f2;
        for(int x:nums1) f1[x]++;
        for(int x:nums2) f2[x]++;
        unordered_set<int> st;
        for(auto &p:f1) st.insert(p.first);
        for(auto &p:f2) st.insert(p.first);
        int moves = 0;
        for(int x:st){
            int total = f1[x] + f2[x];
            if(total % 2) return -1;
            int target = total/2;
            if(f1[x] > target)
                moves += f1[x] - target;
        }
        return moves;
    }
};