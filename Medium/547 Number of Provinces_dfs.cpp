class Solution {
private:
    typedef pair<int,int> pi;
    typedef vector<vector<int>> vvi;
    int count=0;
    void dfs(vvi& isConnected, vector<int>& visited, int i)  {
        
        for(int j=0; j<visited.size(); j++)  {
            if(!visited[j] && isConnected[i][j] == 1)   {
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
        return;
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> visited(n, 0);
        
        for(int i=0; i<n; i++)  {
                if(visited[i] != 1)  {
                    count++;
                    visited[i] = 1;
                    dfs(isConnected, visited, i);
                }
        }
        return count;
    }
};