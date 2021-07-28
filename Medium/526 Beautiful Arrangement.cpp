class Solution {
private:
    int count = 0;
    int xxx = 0;
    void PermutationUtil(int n, vector<int>& perm, vector<int>& visited, vector<int>& ans)  {
        
        if(count == n)  {
            xxx++;
            return;
        }
        
        for(int i=1; i<=n; i++)  {
            int size = perm.size()+1;
            if(!visited[i] && (i%size == 0 || size%i == 0) ) {
                perm.push_back(i);
                count++;
                visited[i] = 1;
                PermutationUtil(n, perm, visited, ans);
                
                perm.pop_back();
                count--;
                visited[i] = 0;
            }
        }
        return;
    }
    
public:
    int countArrangement(int n) {
        if(n == 1) return 1;
        
        vector<int> ans(n+1,0);
        for(int i=1; i<=n; i++)
            ans[i] = i;
        
        vector<int> perm;
        vector<int> visited(n+1,0);
        
        PermutationUtil(n, perm, visited, ans);
        return xxx;
    }
};