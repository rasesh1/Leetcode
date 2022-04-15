typedef long long int lli;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0; i<n; i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        
        int i=0;
        long long time = tasks[0][0];
        vector<int> ans;
        priority_queue<vector<lli>, vector<vector<lli>>, greater<vector<lli>>> pq;
        
        while(ans.size() < n)  {
            while(i<n && tasks[i][0] <= time){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            if(!pq.empty()) {
                vector<long long int> top = pq.top();
                pq.pop();
                ans.push_back(top[1]);
                time = time + top[0];
            }
            else if(i < n) time = tasks[i][0];
        }
        
        return ans;
    }
};