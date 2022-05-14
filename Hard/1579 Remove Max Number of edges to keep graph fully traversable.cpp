class Solution {
private:
    vector<int> parent;
    vector<int> s;
    
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
        
        if(s[p1] < s[p2])   {
            parent[p1] = p2;
            s[p2] = s[p1] + s[p2];
            s[p1] = 0;
        }
        else    {
            parent[p2] = p1;
            s[p1] = s[p1] + s[p2];
            s[p2] = 0;
        }
        return;
    }
    
    bool checkIfPossibleToTraverse()    {
        for(int i=2; i<parent.size(); i++)  {
            if(Find(1) != Find(i)) return false;
        }
        return true;
    }
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for(int i=0; i<=n; i++)  {
            parent.push_back(i);
            s.push_back(1);
        }
        
        int edgesToRemove = 0;
        
        for(auto edge : edges)  {
            if(edge[0] == 3)    {
                if(sameSet(edge[1], edge[2]))
                    edgesToRemove++;
                else
                    Union(edge[1], edge[2]);
            }
        }
        
        vector<int> parentSnapshot = parent;
        vector<int> s_snapshot = s;
        
        for(auto edge : edges)  {
            if(edge[0] == 1)    {
                if(sameSet(edge[1], edge[2]))
                    edgesToRemove++;
                else
                    Union(edge[1], edge[2]);
            }
        }
        
        bool isPossible = checkIfPossibleToTraverse();
        if(!isPossible) return -1;
        
        parent = parentSnapshot;
        s = s_snapshot;
        
        for(auto edge : edges)  {
            if(edge[0] == 2)    {
                if(sameSet(edge[1], edge[2]))
                    edgesToRemove++;
                else
                    Union(edge[1], edge[2]);
            }
        }
        isPossible = checkIfPossibleToTraverse();
        if(!isPossible) return -1;
        
        return edgesToRemove;
    }
};