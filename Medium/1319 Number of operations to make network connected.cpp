class Solution {
private:
    vector<vector<int>> createAdjacencyList(vector<vector<int>>& connections, int n)  {
        vector<vector<int>> adjacencyList(n);
        
        for(auto edge : connections)    {
            int src = edge[0];
            int dest = edge[1];
            
            adjacencyList[src].push_back(dest);
            adjacencyList[dest].push_back(src);
        }
        return adjacencyList;
    }
    
    void dfs(vector<vector<int>>& adjacencyList, vector<int>& visited, int src) {
        for(auto node : adjacencyList[src])  {
            if(!visited[node]) {
                visited[node] = 1;
                dfs(adjacencyList, visited, node);
            }
        }
        return;
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1) return -1;
        
        vector<vector<int>> adjacencyList = createAdjacencyList(connections, n);
        
        vector<int> visited(n,0);
        int numConnections = 0;
        
        for(int i=0; i<n; i++)  {
            if(!visited[i]) {
                visited[i] = 1;
                numConnections++;
                dfs(adjacencyList, visited, i);
            }
        }
        return numConnections-1;
    }
};