class Solution {
private:
    typedef pair<int,int> pi;
    typedef vector<vector<int>> vvi;
    int count=0;
    
    int Find(int i, vector<int>& parent) {
        if(i == parent[i]) return i;
        
        int p = Find(parent[i], parent);
        parent[i] = p;
        return p;
        
    }
    
    bool SameSet(int i, int j, vector<int>& parent) {
        int p1 = Find(i, parent);
        int p2 = Find(j, parent);
        
        if(p1 == p2) return true;
        return false;
    }
    
    bool Union(int i, int j, vector<int>& parent, vector<int>& sizes)   {
        int p1 = Find(i, parent);
        int p2 = Find(j, parent);
        
        if(p1 == p2) return false;
        
        if(sizes[p1] <= sizes[p2])     {
            parent[p1] = p2;
            sizes[p2] = sizes[p1] + sizes[p2];
            sizes[p1] = 0;
        }
        else if(sizes[p1] > sizes[p2])     {
            parent[p2] = p1;
            sizes[p1] = sizes[p1] + sizes[p2];
            sizes[p2] = 0;
        }
        return true;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> parent(n, 0);
        vector<int> sizes(n,1);
        int count = n;
        
        for(int i=0; i<n; i++)
            parent[i] = i;
            
        for(int i=0; i<n; i++)  {
            for(int j=0; j<n; j++)  {
                if(i == j) continue;
                
                if(isConnected[i][j] == 1 && !SameSet(i,j,parent))  {
                    count--;
                    Union(i,j,parent,sizes);
                }
                
            }
        }
        return count;
    }
};