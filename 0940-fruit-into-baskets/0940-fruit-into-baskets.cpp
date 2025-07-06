class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int maxi=1;
        unordered_map<int,int>freq;
        for(int i=0;i<fruits.size();i++){
            freq[fruits[i]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            maxi=max(maxi,i-l+1);

        }
        return maxi;
    }
};