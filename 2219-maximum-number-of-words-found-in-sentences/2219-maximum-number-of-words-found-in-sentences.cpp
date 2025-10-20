class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=0;
        for(int i=0;i< sentences.size();i++){
            string word=sentences[i];
            int curr=0;
            for(auto it:word){
                if(it==' ')curr++;
            }
            curr++;
            count=max(curr,count);

        }
        return count;
    }
};