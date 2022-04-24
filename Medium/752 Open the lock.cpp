class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadEnds;
        for(auto deadend : deadends)
            deadEnds.insert(deadend);
        
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        
        if(deadEnds.find("0000") == deadEnds.end()) {
            q.push(make_pair("0000", 0));
            visited.insert("0000");
        }
        
        while(!q.empty())   {
            pair<string,int> top = q.front(); q.pop();
            string s = top.first;
            int dist = top.second;
            
            if(s == target)
                return dist;
            
            string curr = s;
            for(int i=0; i<4; i++)  {
                // Add 1
                curr[i] = s[i]+1;
                if(s[i] == '9') curr[i] = '0';
                if(visited.find(curr) == visited.end() && deadEnds.find(curr) == deadEnds.end()) {
                    q.push(make_pair(curr, dist+1));
                    visited.insert(curr);
                }
                curr = s;
                
                // Substract 1
                curr[i] = s[i]-1;
                if(s[i] == '0') curr[i] = '9';
                if(visited.find(curr) == visited.end() && deadEnds.find(curr) == deadEnds.end()) {
                    q.push(make_pair(curr, dist+1));
                    visited.insert(curr);
                }
                curr = s;
            }
        }
        return -1;
    }
};