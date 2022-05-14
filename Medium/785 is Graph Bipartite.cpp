class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        queue<int> q;
        
        for(int i=0; i<n; i++)  {
            if(visited[i]) continue;
            
            q.push(i);
            visited[i] = 1;
            
            while(!q.empty())   {
                int top = q.front(); q.pop();
                int node = top;
                int group = visited[node];
                
                int nextGroup = group-1;
                if(group == 1) nextGroup = group+1;
                
                for(auto nbr : graph[node]) {
                    if(visited[nbr])    {
                        if(visited[nbr] == group) return false;
                        continue;
                    }
                    
                    visited[nbr] = nextGroup;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};