class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
           map<int,int>mp;
        for(int i=0;i<bulbs.size();i++){
            mp[bulbs[i]]++;
        }
        vector<int>ans;
       for(auto it : mp){
         if(it.second % 2 == 1){
        ans.push_back(it.first);
    }
}

        return ans;
        
    }
};