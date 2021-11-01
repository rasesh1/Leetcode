typedef vector<vector<int>> vvi;

class Solution {
private:
    vector<vector<int>> ans;
    
    void trackPath(vvi& graph, vector<int>& currPath, int curr)    {
        if(curr==graph.size()-1)  {
            ans.push_back(currPath);
            return;
        }
                
        for(int i=0; i<graph[curr].size(); i++) {
            int nbr = graph[curr][i];
            currPath.push_back(nbr);
            trackPath(graph, currPath, nbr);
            currPath.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> currPath = {0};
        trackPath(graph, currPath, 0);
        return ans;
    }
};