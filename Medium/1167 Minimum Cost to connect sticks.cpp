class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if(n==1) return 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int currCost = 0;
        
        for(auto s : sticks)
            pq.push(s);
        
        while(pq.size() > 1)    {
            int mini = pq.top(); pq.pop();
            int mini2 = pq.top(); pq.pop();
            
            currCost = currCost + mini+mini2;
            pq.push(mini+mini2);
        }
        
        
        return currCost;
    }
};