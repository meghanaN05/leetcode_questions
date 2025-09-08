class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> uniqueTypes(candyType.begin(), candyType.end());
        
        return min((int)uniqueTypes.size(), n/2);
    }
};