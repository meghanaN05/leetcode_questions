class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
             int xor1=0;
            for(int j=i+1;j<arr.size();j++){
                 xor1=xor1^arr[j-1];
                 int xor2=0;
                for(int k=j;k<arr.size();k++){
                    xor2=xor2^arr[k];
                    if(xor1==xor2) count++;
                }
            }
        }
        return count;
    }
};