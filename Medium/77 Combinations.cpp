typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
private:
    vvi ans;
    
    void combineUtil(int n, int k ,vi& curr, int start)    {
        if(curr.size() == k)    {
            ans.push_back(curr);
            return;
        }
        
        for(int i=start; i<=n; i++) {
            curr.push_back(i);
            combineUtil(n, k, curr, i+1);
            curr.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vi curr;
        combineUtil(n, k, curr, 1);
        return ans;
        
    }
};