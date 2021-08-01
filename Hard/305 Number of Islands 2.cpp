typedef pair<int,int> pi;

class UnionFind {
public:
    vector<vector<pi>> parent;
    
    UnionFind(int rows, int cols) {
        for(int i=0; i<rows; i++)   {
            parent.push_back({});
            for(int j=0; j<cols; j++)   {
                parent[i].push_back(make_pair(i,j));
            }
        }
    }
    
    pi Find(pi point)  {
        pi curr_parent = parent[point.first][point.second];
        if(point == curr_parent) return point;
        
        pi p = Find(parent[point.first][point.second]);
        parent[point.first][point.second] = p;
        return p;
    }
    
    bool sameSet(pi point1, pi point2)  {
        pi p1 = Find(point1);
        pi p2 = Find(point2);
        
        if(p1 == p2) return true;
        return false;
    }
    
    bool Union(pi point1, pi point2)   {
        pi p1 = Find(point1);
        pi p2 = Find(point2);
        
        if(p1 == p2) return false;
        
        parent[p1.first][p1.second] = p2;
        return true;
    }
    
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        int islands = 0;
        vector<int> ans;
        
        unordered_map<int, int> encountered;
        vector<vector<int>> grid(m, vector<int>(n,0));
        
        vector<int> xs = {-1,0,1,0};
        vector<int> ys = {0,1,0,-1};
        
        UnionFind* obj = new UnionFind(m,n);
        
        for(auto position : positions)  {
            int x = position[0];
            int y = position[1];
            
            if(encountered.find(n*x+y) != encountered.end()) {
                ans.push_back(islands);
                continue;
            }
            
            grid[x][y] = 1;
            islands++;

            for(int k=0; k<4; k++)  {
                int i = x + xs[k];
                int j = y + ys[k];

                if(i>=0 && j>=0 && i<m && j<n && grid[i][j] == 1) {
                    bool temp = obj->Union(make_pair(x,y), make_pair(i,j));
                    if(temp) islands--;
                }
            }
            encountered[n*x+y] = islands;
            ans.push_back(islands);
        }
        return ans;
    }
};