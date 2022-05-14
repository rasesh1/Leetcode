class Solution {
private:
    void createGraph(vector<vector<int>>& dislikes, vector<vector<int>>& graph)  {
        for(auto dislike : dislikes)    {
            int src = dislike[0];
            int dest = dislike[1];
            
            graph[src].push_back(dest);
        }
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        createGraph(dislikes, graph);
        
        vector<int> visited(n+1,0);
        queue<pair<int,int>> q;
        int count = 0;
        
        for(int i=1; i<=n; i++)  {
            int firstGroup = 2*count + 1;
            count++;
            
            if(visited[i]) continue;
            
            q.push(make_pair(i, firstGroup));
            visited[i] = firstGroup;
            while(!q.empty())   {
                pair<int,int> top = q.front(); q.pop();
                int node = top.first;
                int group = top.second;
                int nextGroup = group - 1;
                if(group%2 == 1) nextGroup = group + 1;
                
                for(auto nbr : graph[node]) {
                    if(visited[nbr])    {
                        if(visited[nbr] == group) return false;
                        continue;
                    }
                    visited[nbr] = nextGroup;
                    q.push(make_pair(nbr, nextGroup));
                }
            }
        }
        return true;
    }
};