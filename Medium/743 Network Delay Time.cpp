typedef pair<int,int> pi;
typedef vector<int> vi;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pi>> graph(n+1, vector<pi>({}));
        int nodesReached = 0;
        vector<int> visited(n+1,0);
        
        for(auto time : times)  {
            int src = time[0];
            int dest = time[1];
            int t = time[2];
            
            graph[src].push_back(make_pair(dest,t));
        }
        
        int ans = 0;
        int src = k;
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        pq.push({0, k});
        
        while(!pq.empty())  {
            vi top = pq.top(); pq.pop();
            int node = top[1];
            int t = top[0];
            
            if(visited[node] > 0) continue;
            visited[node] = 1;
            ans = max(ans,t);
            nodesReached++;
            
            for(auto nbr : graph[node]) {
                int nbr_node = nbr.first;
                int weight = nbr.second;
                
                if(visited[nbr_node]) continue;
                pq.push({t+weight, nbr_node});
            }
        }
        if(nodesReached != n) return -1;
        return ans;
    }
};