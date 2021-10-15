class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    
    int Find(int x) {
        if(x == parent[x]) return x;
        
        int px = Find(parent[x]);
        parent[x] = px;
        return px;
    }
    
public:
    UnionFind(int n)    {
        for(int i=0; i<n; i++)  {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    bool Union(int x, int y)    {
        int px = Find(x);
        int py = Find(y);
        
        if(px == py) return false;
        
        if(size[px] < size[py]) {
            parent[px] = py;
            size[py] = size[px]+size[py];
            size[px]=0;
        }
        else    {
            parent[py] = px;
            size[px] = size[px]+size[py];
            size[py]=0;
        }
        return true;
    }
    
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        
        int components = n;
        UnionFind* obj = new UnionFind(n);
        
        for(auto log : logs)    {
            if(obj->Union(log[1], log[2])) components--;
            
            if(components == 1) return log[0];
        }
        return -1;
    }
};