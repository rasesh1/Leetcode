typedef pair<int,double> pi;

class Solution {
private:
    double maxProb = 0;
    double dfs(vector<vector<pi>>& graph, int start, int end, vector<double>& succProb, vector<double>& A, double currProb, vector<int>& visited)    {
        
        if(A[start] > 0) {
            maxProb = max(maxProb, currProb*A[start]);
            return currProb*A[start];
        }
        
        if(start == end) {
            maxProb = max(maxProb, currProb);
            return currProb;
        }
        
        for(auto nbr : graph[start])    {
            int node = nbr.first;
            double p = nbr.second;
            
            if(visited[node]) {
                maxProb = max(maxProb, A[node]);
                continue;
            }
            
            visited[node] = 1;
            double ans = dfs(graph, node, end, succProb, A, currProb*p, visited);
            visited[node] = 0;
            A[start] = max(currProb*ans, A[start]);
        }
        return A[start];
    }
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 1;
        vector<vector<pi>> graph(n, vector<pi>({}));
        
        for(int i=0; i<edges.size(); i++)  {
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            double prob = succProb[i];
            
            graph[src].push_back(make_pair(dest,prob));
            graph[dest].push_back(make_pair(src,prob));
        }
        
        vector<double> A(n,0);
        vector<int> visited(n,0);
        visited[start] = 1;
        dfs(graph, start, end, succProb, A, 1, visited);
        return maxProb;
    }
};