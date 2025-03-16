class Solution {
    vector<vector<int>>combinations;
    vector<int>CurrSub;
    void  backtrack(int index,int target,vector<int>& candidates){
        if(target==0){
            combinations.push_back(CurrSub);
            return;
        }
        if(index==candidates.size()|| target<0){
            return ;
        }
        //you are not choosing the elemt
        backtrack(index+1,target,candidates);
        // you are choosing the elemt
        CurrSub.push_back(candidates[index]);
        backtrack(index,target-candidates[index],candidates);
        CurrSub.pop_back();
        
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0,target,candidates);
        return combinations;
         
    }
};