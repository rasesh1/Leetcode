class unionFind {
public:
    vector<int> parent;
    vector<int> root;
    
    unionFind(int n) {
        parent.resize(n+1);
        root.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            root[i] = i;
        }
    }
    
    int FindRoot(int i)  {
        if(i == root[i]) return i;
        
        int j = FindRoot(root[i]);
        root[i] = j;
        return j;
    }
    
    bool Union(int i, int j)    {
        int p1 = FindRoot(i);
        int p2 = FindRoot(j);
        
        if(p1 == p2) return true;
        
        root[j] = p1;
        return false;
    }
    
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        unionFind* obj = new unionFind(n);
        
        vector<int> nodesToCheck(2,-1);
        int twoEdges = -1;
        vector<int> toRemove = {};
        
        for(auto edge : edges)   {
            int x = edge[0];
            int y = edge[1];
            
            if(obj->parent[y] != y && obj->parent[y] != x)  {
                nodesToCheck = {obj->parent[y],x};
                twoEdges = y;
                obj->parent[y] = y;
            }
            else    {
                obj->parent[y] = x;
                bool sameSet = obj->Union(x,y);
                if(sameSet) toRemove = {edge[0],edge[1]};
            }
        }
        
        if(nodesToCheck[0] != -1) {
            int v1 = nodesToCheck[0];
            int v2 = nodesToCheck[1];

            if(obj->FindRoot(v2) == obj->FindRoot(twoEdges)) return {v2,twoEdges};
            else return {v1,twoEdges};
        }
        return toRemove;
    }
};