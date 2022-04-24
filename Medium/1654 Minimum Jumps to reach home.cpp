class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbidden_set;
        for(auto forbid : forbidden)
            forbidden_set.insert(forbid);

        unordered_set<int> visited;
        queue<vector<int>> q;
        q.push({0,-1,0});
        visited.insert(0);
        
        while(!q.empty())   {
            vector<int> top = q.front(); q.pop();
            int pos = top[0];
            int from = top[1];
            int dist = top[2];
            
            if(pos == x) return dist;
            
            if(visited.find(pos+a) == visited.end() && forbidden_set.find(pos+a) == forbidden_set.end() && pos+a <= 6000 + max(a,b))    {
                q.push({pos+a, pos, dist+1});
                visited.insert(pos+a);
            }
            
            if(from <= pos && visited.find(pos-b) == visited.end() && forbidden_set.find(pos-b) == forbidden_set.end() && pos-b >= 0) {
                q.push({pos-b, pos, dist+1});
            }
        }
        return -1;
    }
};