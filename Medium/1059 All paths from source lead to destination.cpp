typedef vector<vector<int>> vvi;

class Solution {
private:
    vvi buildAdjacencyList(vvi& edges, int n)  {
        vvi graph(n);
        
        for(auto edge : edges)  {
            graph[edge[0]].push_back(edge[1]);
        }
        return graph;
    }
    
    bool dfs(vvi& graph, int src, int dest, vector<int> visited) {
        if(src == dest) {
            return true;
        }
        
        if(graph[src].size() == 0) return false;
        
        for(auto node : graph[src])  {
            if(visited[node]) return false;
            
            visited[node] = 1;
            if(!dfs(graph, node, dest, visited)) return false;
            visited[node] = 0;            
        }
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vvi graph = buildAdjacencyList(edges, n);
        if(graph[destination].size() > 0)  return false;
        
        vector<int> visited(n,0);
        visited[source] = 1;
        return dfs(graph, source, destination, visited);
    }
};