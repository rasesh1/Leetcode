typedef vector<int> vi;

class Solution {
private:
    vector<int> parent;
    vector<int> size;
    
    int Find(int i) {
        if(i == parent[i]) return i;
        int p = Find(parent[i]);
        parent[i] = p;
        return p;
    }
    
    bool sameSet(int i, int j)  {
        return Find(i) == Find(j);
    }
    
    void Union(int i, int j)    {
        int p1 = Find(i);
        int p2 = Find(j);
        
        if(p1 == p2) return;
        
        if(size[p1] < size[p2]) {
            parent[p1] = parent[p2];
            size[p2] = size[p1] + size[p2];
            size[p1] = 0;
        }
        else{
            parent[p2] = parent[p1];
            size[p1] = size[p1] + size[p2];
            size[p2] = 0;
        }
        return;
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        size.resize(n,1);
        
        for(int i=0; i<n; i++)    {
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j=i+1; j<n; j++)    {
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                pq.push( { abs(x1-x2) + abs(y1-y2), i, j} );
            }
        }
        
        int numSets = n;
        int cost = 0;
        while(numSets > 1)  {
            vector<int> top = pq.top(); pq.pop();
    
            if(sameSet(top[1], top[2])) continue;
            
            numSets--;
            cost = cost + top[0];
            Union(top[1],top[2]);
        }
        return cost;
    }
};