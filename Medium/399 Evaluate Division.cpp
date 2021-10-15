typedef pair<int,double> pi;
typedef vector<vector<pi>> graph;
typedef vector<vector<string>> vvs;
typedef unordered_map<string,int> msi;

class Solution {
private:
    int index=0;
    graph buildAdjacencyList(msi& mp, vvs& equations, vector<double>& values)   {
        graph g;
        for(int i=0; i<equations.size(); i++)   {
            string num = equations[i][0];
            string denom = equations[i][1];
            double val = values[i];
            
            if(mp.find(num) == mp.end()) mp[num] = index++;
            if(mp.find(denom) == mp.end()) mp[denom] = index++;
            
            if(g.size() <= mp[num]) g.push_back({});
            if(g.size() <= mp[denom]) g.push_back({});
            
            g[mp[num]].push_back(make_pair(mp[denom], val));
            g[mp[denom]].push_back(make_pair(mp[num], 1.0/val));
        }
        
        return g;
    }
    
    double bfs(graph& g, msi& mp, string num, string denom)    {
        int src = mp[num];
        int dest = mp[denom];
        int n = mp.size();
        vector<int> visited(n,0);
        
        queue<pi> q;
        q.push(make_pair(src, 1));
        visited[src] = 1;
        
        while(!q.empty())   {
            pi top = q.front(); q.pop();
                        
            for(int i=0; i<g[top.first].size(); i++) {
                pi nbr = g[top.first][i];
                
                if(nbr.first == dest) return top.second*nbr.second;
                if(!visited[nbr.first])    {
                    visited[nbr.first] = 1;
                    q.push(make_pair(nbr.first, nbr.second*top.second));
                }
            }
        }
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        vector<double> ans;
        
        int n = equations.size();
        graph g = buildAdjacencyList(mp, equations, values);
        
        for(auto query : queries)   {
            string num = query[0];
            string denom = query[1];
            
            if(mp.find(num) == mp.end() || mp.find(denom) == mp.end())    {
                ans.push_back(-1);
                continue;
            }
            
            if(num == denom) {
                ans.push_back(1);
                continue;
            }
            
            double res = bfs(g, mp, num, denom);
            ans.push_back(res);
        }
        return ans;
    }
};