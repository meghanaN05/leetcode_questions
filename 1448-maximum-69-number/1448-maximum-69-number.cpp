class Solution {
public:
    int maximum69Number (int num) {
        vector<int>a;
        while(num>0){
            a.push_back(num%10);
          num=num/10;
        }
        reverse(a.begin(),a.end());
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==6){
                count++;
                a[i]=9;
            }
            if(count==1){
                break;
            }
        }
        string result="";
       

    for(int i = 0; i <a.size(); i++) {
        result += to_string(a[i]);  
        
    }
   int ans=stoi(result);
   return ans;
    }
};