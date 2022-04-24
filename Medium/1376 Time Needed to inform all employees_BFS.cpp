class Solution {
private:
    int maxTime = 0;
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<vector<int>> q;
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++)  {
            int manager_ = manager[i];
            int employee = i;
            
            if(mp.find(manager_) == mp.end()) mp[manager_] = {};
            mp[manager_].push_back(employee);
        }
        
        q.push({headID, informTime[headID]});
        while(!q.empty())   {
            vector<int> top = q.front(); q.pop();
            int manager_ = top[0];
            int time = top[1];
            
            for(auto employee : mp[manager_])   {
                q.push({employee, time + informTime[employee]});
                maxTime = max(maxTime, time + informTime[employee]);
            }
        }
        return maxTime;
    }
};