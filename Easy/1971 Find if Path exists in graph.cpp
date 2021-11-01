typedef vector<vector<int>> vvi;
typedef vector<vector<int>> graph;

class Solution {
private:
    graph buildGraph(vvi& edges, int n)    {
        graph g(n);
        
        for(auto edge : edges)  {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        return g;
    }
    
    bool dfs(vvi& g, int src, int dest, vector<int>& visited, int curr) {
        visited[curr] = 1;
        for(int i=0; i<g[curr].size(); i++)  {
            int node = g[curr][i];
            if(node == dest) return true;
            if(!visited[node])  {
                bool ifPath = dfs(g, src, dest, visited, node);
                if(ifPath) return true;
            }
        }
        return false;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(start == end) return true;
        graph g = buildGraph(edges, n);
        vector<int> visited(n,0);
        bool ifPath = dfs(g, start, end, visited, start);
        return ifPath;
    }
};