class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> visited(n,0);
        unordered_map<int,int> visited_val;
        
        unordered_map<int,vector<int>> val_index;
        for(int i=0; i<n; i++)   {
            int a = arr[i];
            if(val_index.find(a) == val_index.end())
                val_index[a] = {};
            val_index[a].push_back(i);
        }
        
        queue<vector<int>> q;
        q.push({0,0});
        visited[0] = 1;
        
        while(!q.empty())   {
            vector<int> top = q.front(); q.pop();
            int index = top[0];
            int dist = top[1];
            
            if(index == n-1) return dist;
            
            if(index+1 < n && !visited[index+1])    {
                q.push({index+1,dist+1});
                visited[index+1] = 1;
            }
            
            if(index-1 >= 0 && !visited[index-1])   {
                q.push({index-1,dist+1});
                visited[index-1] = 1;
            }
            
            if(visited_val.find(arr[index]) != visited_val.end()) continue;
            
            vector<int> nbrs = val_index[arr[index]];
            for(int i=0; i<nbrs.size(); i++)   {
                int nbr = nbrs[i];
                if(nbr == index) continue;
                
                if(!visited[nbr])   {
                    visited[nbr] = 1;
                    q.push({nbr,dist+1});
                }
            }
            visited_val[arr[index]] = 1;
        }
        return -1;
    }
};