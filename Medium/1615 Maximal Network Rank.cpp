class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n, vector<int>(n,0));
        vector<int> indegree(n,0);
        
        // Create Graph
        for(auto road : roads)  {
            int n1 = road[0];
            int n2 = road[1];
            
            indegree[n1]++;
            indegree[n2]++;
            
            graph[n1][n2] = 1;
            graph[n2][n1] = 1;
        }
        
        int maxRank = 0;
        for(int i=0; i<n; i++)  {
            for(int j=i+1; j<n; j++)    {
                int rank = indegree[i]+indegree[j];
                if(graph[i][j] == 1) rank--;
                maxRank = max(maxRank, rank);
            }
        }
        return maxRank;
    }
};