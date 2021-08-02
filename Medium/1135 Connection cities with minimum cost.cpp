class unionFind {
public:
    vector<int> parent;
    vector<int> sizes;
    
    unionFind(int n) {
        parent.resize(n+1);
        sizes.resize(n+1);
        
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }
    
    int find(int i) {
        if(i == parent[i]) return i;
        
        int j = find(parent[i]);
        parent[i] = j;
        return j;
    }
    
    bool Union(int i, int j)    {
        int p1 = find(i);
        int p2 = find(j);
        
        if(p1 == p2) return false;
        
        if(sizes[p1] < sizes[p2])   {
            parent[p1] = p2;
            sizes[p2] = sizes[p1] + sizes[p2];
            sizes[p1] = 0;
        }
        else    {
            parent[p2] = p1;
            sizes[p1] = sizes[p1] + sizes[p2];
            sizes[p2] = 0;
        }
        return true;
    }
};

class Solution {
private:
    static bool cmp(const vector<int> v1, const vector<int> v2) {
        return v1[2] < v2[2];
    }
    
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        
        int totalCost=0;
        int count=n;
        
        sort(connections.begin(), connections.end(), cmp);
        unionFind* obj = new unionFind(n);
        
        for(auto connection : connections)  {
            int x = connection[0];
            int y = connection[1];
            int cost = connection[2];
            
            if(obj->Union(x,y)) {
                totalCost = totalCost + cost;
                count--;
            }
        }
        
        return count==1 ? totalCost : -1;
    }
};