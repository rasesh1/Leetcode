class Solution {
public:
    unordered_map<int, vector<int>> mp;
    
    vector<int> beautifulArray(int n) {
        
        if(mp.find(n) != mp.end())  {
            return mp[n];
        }
    
        vector<int> ans(n,0);
        if(n == 1)
            ans[0] = 1;
        else    {
            int index=0;
            for(int x : beautifulArray((n+1)/2))
                ans[index++] = 2*x - 1;
                
            for(int x : beautifulArray(n/2))
                ans[index++] = 2*x;
        }
        
        mp[n] = ans;
        return ans;
    }
};