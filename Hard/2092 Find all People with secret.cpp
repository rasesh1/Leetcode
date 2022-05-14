static bool cmp(const vector<int>& v1, const vector<int>& v2)   {
    return v1[2] < v2[2];
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), cmp);
        vector<int> ans = {0, firstPerson};
        vector<int> secret(n,-1);
        secret[0] = 0;
        secret[firstPerson] = 0;
        
        int i=0;
        while(i<meetings.size())  {
            vector<vector<int>> meetingAtTime;
            int currTime = meetings[i][2];
            
            int j = i;
            
            queue<int> q;
            unordered_map<int,vector<int>> graph;
            
            while(j < meetings.size())    {
                vector<int> next_meeting = meetings[j];
                if(currTime == next_meeting[2]) {
                    j++;
                    
                    meetingAtTime.push_back(next_meeting);
                    
                    int p1 = next_meeting[0];
                    int p2 = next_meeting[1];
                    
                    if(graph.find(p1) == graph.end()) {
                        graph[p1] = {};
                        if(secret[p1] > -1) q.push(p1);
                    }
                    if(graph.find(p2) == graph.end()) {
                        graph[p2] = {};
                        if(secret[p2] > -1) q.push(p2);
                    }
                
                    graph[p1].push_back(p2);
                    graph[p2].push_back(p1);
                }
                else break;
            }
            i = j;
            
            while(!q.empty())   {
                int top = q.front(); q.pop();
                
                for(auto nbr : graph[top])  {
                    if(secret[nbr] == -1)    {
                        secret[nbr] = currTime;
                        q.push(nbr);
                        ans.push_back(nbr);
                    }
                }
            }
        }
        
        return ans;
    }
};