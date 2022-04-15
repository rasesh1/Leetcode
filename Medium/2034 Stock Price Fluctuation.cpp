class StockPrice {
private:
    int lastTime;
    unordered_map<int,int> mp;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
    priority_queue<vector<int>> maxHeap;
    
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        mp[timestamp] = price;
        lastTime = max(timestamp, lastTime);
        minHeap.push({price,timestamp});
        maxHeap.push({price,timestamp});
        return;
    }
    
    int current() {
        return mp[lastTime];
    }
    
    int maximum() {
        while(!maxHeap.empty())  {
            vector<int> top = maxHeap.top();
            int time = top[1];
            if(mp[time] == top[0]) return top[0];
            else maxHeap.pop();
        }
        return 0;
    }
    
    int minimum() {
        while(!minHeap.empty())  {
            vector<int> top = minHeap.top();
            int time = top[1];
            if(mp[time] == top[0]) return top[0];
            else minHeap.pop();
        }
        return 0;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */