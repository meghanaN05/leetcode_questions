class StockSpanner {
public:
stack<int>st;
vector<int>ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
          int cnt=0;
          for(int i=0;i<ans.size();i++){
            if(ans[i]<=price)
            cnt++;
            else
            cnt=0;
          }
          return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */