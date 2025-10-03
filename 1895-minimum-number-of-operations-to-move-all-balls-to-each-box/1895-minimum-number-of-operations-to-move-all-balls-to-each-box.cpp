class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>index;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                index.push_back(i);
            }
        }
        vector<int>ans(boxes.size());
        for(int i=0;i<boxes.size();i++){
            for(int j=0;j<index.size();j++){
                ans[i]+=abs(index[j]-i);
            }
        }
        return ans;
    }
};