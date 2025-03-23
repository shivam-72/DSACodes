class StockSpanner {
public:
   stack<pair<int,int>>pq;
   int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
       while(pq.size()>0&&pq.top().first<=price){
        pq.pop();
       }
       int ans=0;
       if(pq.size()>0)
        ans=i-pq.top().second;
        else{
            ans=i+1;
        }
       pq.push({price,i});
       i++;
       return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */