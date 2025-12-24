class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum=0;
        int s=accumulate(apple.begin(),apple.end(),0);
        for(int i=0;i<capacity.size();i++){
            sum+=capacity[i];
            if(sum>=s) return i+1;
        }
        return -1;
    }
};