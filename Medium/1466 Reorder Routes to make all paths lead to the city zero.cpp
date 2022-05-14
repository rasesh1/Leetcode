class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        vector<vector<int>> graph(n);
        vector<vector<int>> reverse_graph(n);
        vector<int> visited(n,0);
        
        for(auto connection : connections)  {
            int src = connection[0];
            int dest = connection[1];
            
            reverse_graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty())   {
            int top = q.front(); q.pop();
            
            for(auto nbr : graph[top])  {
                if(!visited[nbr])   {
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
            
            for(auto nbr : reverse_graph[top])  {
                if(!visited[nbr])   {
                    visited[nbr] = 1;
                    q.push(nbr);
                    count++;
                }
            }
        }
        return count;
    }
};