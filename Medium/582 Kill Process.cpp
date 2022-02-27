class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        if(n == 0) return {};
        
        vector<int> ans;
        unordered_map<int, vector<int>> children;
        
        for(int i=0; i<n; i++)  {
            int process = pid[i];
            int parent = ppid[i];
            
            if(children.find(parent) == children.end()) children[parent] = {};
            children[parent].push_back(process);
        }
        
        queue<int> q;
        q.push(kill);
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            
            vector<int> processes = children[top];
            for(auto p : processes) q.push(p);
        }
        return ans;
    }
};