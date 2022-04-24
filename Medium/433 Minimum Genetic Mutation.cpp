class Solution {
private:
    bool isMutation(string& s1, string& s2)  {
        int dist=0;
        for(int i=0; i<8; i++)  {
            if(s1[i] != s2[i]) dist++;
        }
        return dist==1;
    }
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        int n = bank.size();
        unordered_map<string, vector<string>> graph;
        unordered_map<string,int> visited;
        
        for(auto s : bank)  {
            graph[s] = {};
            visited[s] = 0;
        }
            
        
        for(int i=0; i<n; i++)  {
            for(int j=0; j<n; j++)  {
                if(isMutation(bank[i], bank[j]))    {
                    graph[bank[i]].push_back(bank[j]);
                    graph[bank[j]].push_back(bank[i]);
                }
            }
        }
        
        queue<pair<string,int>> q;
        q.push(make_pair(start,0));
        visited[start] = 1;
        
        while(!q.empty())   {
            pair<string,int> top = q.front(); q.pop();
            string s = top.first;
            int dist = top.second;
            
            for(auto nbr : graph[s])    {
                if(visited[nbr]) continue;
                if(nbr == end) return dist+1;
                
                q.push(make_pair(nbr, dist+1));
                visited[nbr] = 1;
            }
        }
        return -1;
    }
};