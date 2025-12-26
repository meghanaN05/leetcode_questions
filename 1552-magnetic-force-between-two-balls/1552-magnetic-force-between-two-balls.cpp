class Solution {
public:
int db(vector<int>& position, int mid){
    int b=1;
    int i=0;
    int j=i+1;
    while(j<position.size()){
        if(position[j]-position[i]>=mid){
            b++;
            i=j;
            j=j+1;
        }
        else{
            j++;
        }
    }
    return b;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l = 1; 
        int r = position.back() - position.front();
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
           if(db(position,mid)>=m){
            ans=mid;
            l=mid+1;
           }
           else{
            r=mid-1;
           }
        }
       return ans;
    }
};