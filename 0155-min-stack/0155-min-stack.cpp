class MinStack {
public:
 long long mn=LLONG_MAX;
 stack<long long>pq;
    MinStack() {
        
    }
    
    void push(int val) {
       if(pq.size()==0){
        mn=val;
        pq.push(val);
       }
       else{
        if(val<mn){
          pq.push((long long)2*val-mn);
          mn=val;
        }
        else{
            pq.push(val);
        }
       } 
    }
    
    void pop() {
        if(mn>pq.top()){
            int a=pq.top();
            mn=2*mn-a;
        }
         pq.pop();
    }
    
    int top() {
       if(mn>pq.top()){
          return mn;
        }
        else
            return pq.top();
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
