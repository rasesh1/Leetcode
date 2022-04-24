typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
private:
    bool dfs(vvi& graph, int src, vi& terminalNodes, vi& isSafe, vi& visited)    {
        vector<int> nbrs = graph[src];
        isSafe[src] = 1;
        
        if(terminalNodes[src] == 1) return true;
        
        for(auto nbr : nbrs)    {
            
            if(!visited[nbr])   {
                visited[nbr] = 1;
                if(isSafe[nbr] == -1) isSafe[nbr] = dfs(graph, nbr, terminalNodes, isSafe, visited);
                isSafe[src] = isSafe[nbr] && isSafe[src];
                visited[nbr] = 0;
            }
            else isSafe[src] = 0;
        }
        return isSafe[src];
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> terminalNodes(n,0);
        vector<int> isSafe(n,-1);
        vector<int> ans;
        
        for(int i=0; i<n; i++)   {
            if(graph[i].size() == 0) {
                terminalNodes[i] = 1;
                isSafe[i] = 1;
            }
        }
        
        for(int i=0; i<n; i++)  {
            vector<int> visited(n,0);
            if(isSafe[i] == -1)  {
                visited[i] = 1;
                isSafe[i] = dfs(graph, i, terminalNodes, isSafe, visited);
            }
        }
        
        for(int i=0; i<n; i++)  {
            if(isSafe[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};