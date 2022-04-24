class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n,0);
                
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty())   {
            int top = q.front(); q.pop();
            int val = arr[top];
            
            if(val == 0) return true;
            
            if(top + val < n && !visited[top + val])    {
                q.push(top + val);
                visited[top+val] = 1;
            }
            
            if(top - val >= 0 && !visited[top - val])    {
                q.push(top - val);
                visited[top-val] = 1;
            }
        }
        return false;
    }
};