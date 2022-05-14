class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n,-1));
        
        for(auto edge : edges)  {
            int src = edge[0];
            int dest = edge[1];
            int weight = edge[2];
            
            graph[src][dest] = weight;
            graph[dest][src] = weight;
        }
        
        for(int k=0; k<n; k++)  {
            for(int i=0; i<n; i++)  {
                for(int j=0; j<n; j++)  {
                    
                    if(i == j) graph[i][j] = 0;
                    
                    if(graph[i][k] == -1 || graph[k][j] == -1) continue;
                    
                    if(graph[i][j] == -1)  {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                    
                    else if( graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        
        int ans = 0;
        int minCities = n;
        for(int i=0; i<n; i++)  {
            int count = 0;
            for(int j=0; j<n; j++)  {
                if(graph[i][j] <= distanceThreshold)
                    count++;
            }
            if(count <= minCities)  {
                minCities = count;
                ans = i;
            }
        }
        return ans;
    }
};