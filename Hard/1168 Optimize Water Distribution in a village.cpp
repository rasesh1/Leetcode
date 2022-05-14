static bool cmp(const vector<int>& v1, const vector<int>& v2)   {
    return v1[2] < v2[2];
}

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
        
        if(size[p1] < size[p2]) {
            parent[p1] = p2;
            size[p2] = size[p1] + size[p2];
            size[p1] = 0;
        }
        else    {
            parent[p2] = p1;
            size[p1] = size[p1] + size[p2];
            size[p2] = 0;
        }
        return;
    }
    
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        parent.resize(n+1,0);
        for(int i=1; i<=n; i++) parent[i] = i;
        size.resize(n+1,1);
        
        for(int i=0; i<n; i++)      {
            pipes.push_back({0,i+1,wells[i]});
        }
        
        sort(pipes.begin(), pipes.end(), cmp);
        
        int ans = 0;
        for(auto pipe : pipes)  {
            int src = pipe[0];
            int dest = pipe[1];
            int cost = pipe[2];
            
            if(sameSet(src,dest)) continue;
            
            Union(src, dest);
            ans = ans + cost;
        }
        return ans;
    }
};