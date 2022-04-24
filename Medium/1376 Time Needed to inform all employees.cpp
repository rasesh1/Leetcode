class Solution {
private:
    int maxTime = 0;
    int dfs(int n, int employee, vector<int>& manager, vector<int>& informTime, vector<int>& timeReqd)    {
        if(timeReqd[employee]) return timeReqd[employee];
        
        int manager_ = manager[employee];
        int time = informTime[employee] + dfs(n, manager_, manager, informTime, timeReqd);
        maxTime = max(maxTime, time);
        return time;
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return informTime[0];
        
        vector<int> timeReqd(n,0);
        timeReqd[headID] = informTime[headID];
        maxTime = informTime[headID];
        
        for(int i=0; i<n; i++)  {
            if(!timeReqd[i])    {
                timeReqd[i] = dfs(n, i, manager, informTime, timeReqd);
            }
        }
        return maxTime;
    }
};