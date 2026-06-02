class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int maxi=INT_MAX;
        int mini=maxi;
        int res=mini;
        for(int i=0;i<landStartTime.size();i++){
            maxi=min(maxi,landStartTime[i]+landDuration[i]);
        }
         for(int i=0;i<waterStartTime.size();i++){
            mini=min(mini,waterStartTime[i]+waterDuration[i]);
            res=min(res,max(maxi,waterStartTime[i])+waterDuration[i]);
        }
                for (int i = 0;i<landStartTime.size(); i++)
            res = min(res, max(mini, landStartTime[i]) +landDuration[i]);
        return res;
    }
};