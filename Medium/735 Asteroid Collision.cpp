class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        
        if(n <= 1) return asteroids;
        
        ans.push_back(asteroids[0]);
        for(int i=1; i<n; i++)  {
            
            int curr = asteroids[i];
            if(ans.size() == 0) {
                ans.push_back(curr);
                continue;
            }
            int last = ans[ans.size()-1];
            
            if(last > 0 && curr < 0)    {
                while(ans.size() > 0 && last > 0 && curr < 0 && last+curr <= 0)    {
                    ans.pop_back();
                    if(last+curr == 0)  {
                        curr = 0;
                        break;
                    }
                    if(ans.size()>0)    {
                        last = ans[ans.size()-1];
                    }
                }
                if(curr == 0) continue;
                if(ans.size() == 0 || (ans.size()>0 && ans[ans.size()-1]+curr<0)) ans.push_back(curr);
            }
            else ans.push_back(curr);
            
        }
        return ans;
    }
};