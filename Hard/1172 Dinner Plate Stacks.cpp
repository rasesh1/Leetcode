class DinnerPlates {
private:
    vector<stack<int>> vs;
    int threshold=0;
    int index=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
public:
    DinnerPlates(int capacity) {
        threshold = capacity;
        vs.push_back(stack<int>());
    }
    
    void push(int val) {
        
        int topIndex = INT_MAX;
        if(!pq.empty()) {
            topIndex = pq.top();
            pq.pop();
        }
        
        if(index < topIndex)    {
            while(!pq.empty()) pq.pop();
            
            if(vs[index].size() >= threshold)   {
                index++;
                vs.push_back(stack<int>());
            }
            vs[index].push(val);
        }
        
        else vs[topIndex].push(val);
        return;
    }
    
    int pop() {
        while(vs[index].empty() && index>0) index--;
        if(index == 0 && vs[index].empty()) return -1;
        
        int top = vs[index].top();
        vs[index].pop();
        if(vs[index].empty() && index>0) index--;
        return top;
    }
    
    int popAtStack(int index_) {
        if(index_ > index) return -1;
        
        pq.push(index_);
        if(vs[index_].size() > 0)   {
            int top = vs[index_].top();
            vs[index_].pop();
            return top;
        }
            
        return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */