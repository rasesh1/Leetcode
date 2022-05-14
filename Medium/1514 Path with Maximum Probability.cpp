typedef pair<int,double> pi;
typedef pair<double,int> pd;

class Solution {
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pi>> graph(n, vector<pi>({}));
        
        for(int i=0; i<edges.size(); i++)  {
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            double prob = succProb[i];
            
            graph[src].push_back(make_pair(dest,prob));
            graph[dest].push_back(make_pair(src,prob));
        }
        
        priority_queue<pd> pq;
        vector<int> visited(n,0);
        visited[start] = 1;
        pq.push({1,start});
        
        while(!pq.empty())  {
            pd top = pq.top(); pq.pop();
            int node = top.second;
            double prob = top.first;
            
            visited[node] = 1;
            if(node == end) return prob;
            
            for(auto nbr : graph[node]) {
                if(visited[nbr.first] > 0) continue;
                
                pq.push({prob*nbr.second, nbr.first});
            }
        }
        return 0;
    }
};