class Solution {
private:
    int Find(int i, vector<int>& parent)    {
        if(i == parent[i]) return i;
        
        int p = Find(parent[i], parent);
        parent[i] = p;
        return p;
    }
    
    bool SameSet(int i, int j, vector<int>& parent) {
        int p1 = Find(i,parent);
        int p2 = Find(j, parent);
        
        if(p1 == p2) return true;
        return false;
    }
    
    void Union(int i, int j, vector<int>& parent, vector<int>& sizes)   {
        int p1 = Find(i,parent);
        int p2 = Find(j,parent);
        
        if(sizes[p1] <= sizes[p2])    {
            parent[p1] = p2;
            sizes[p2] = sizes[p1]+sizes[p2];
            sizes[p1] = 0;
        }
        else    {
            parent[p2] = p1;
            sizes[p1] = sizes[p1]+sizes[p2];
            sizes[p2] = 0;
        }
        return;
    }
        
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> sizes(n,1);
        int count = n;
        vector<int> parent;
        for(int i=0; i<n; i++)
            parent.push_back(i);
        
        for(auto edge : edges)   {
            int v1 = edge[0];
            int v2 = edge[1];
            
            if(!SameSet(v1,v2,parent))    {
                count--;
                Union(v1,v2,parent,sizes);
            }
        }
        return count;
    }
};